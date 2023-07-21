/*
https://leetcode.com/problems/product-of-array-except-self/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

	int n = nums.size();
	vector<int> pf(n + 2, 1), sf(n + 2, 1);

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] * nums[i - 1];
	}

	for (int i = n; i >= 1; --i) {
		sf[i] = sf[i + 1] * nums[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		nums[i - 1] = pf[i - 1] * sf[i + 1];
	}

	return nums;
}

int main() {
	// vector<int> nums = {1, 2, 3, 4};
	vector<int> nums = { -1, 1, 0, -3, 3};

	auto res = productExceptSelf(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}