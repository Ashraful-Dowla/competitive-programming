/*
https://leetcode.com/problems/product-of-array-except-self/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

	int n = nums.size();
	int product = 1, z = 0;

	for (int i = 0; i < n; ++i) {
		if (nums[i] == 0) {
			z++;
			continue;
		}
		product *= nums[i];
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] == 0) {
			if (z == 1) {
				nums[i] = product;
			}
		}
		else {
			if (z > 0) {
				nums[i] = 0;
			}
			else {
				nums[i] = product / nums[i];
			}
		}
	}

	return nums;
}

int main() {
	vector<int> nums = {1, 2, 3, 4};
	// vector<int> nums = { -1, 1, 0, -3, 3};

	auto res = productExceptSelf(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}