/*
https://leetcode.com/problems/single-number-iii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {

	vector<int> ans(2, 0);

	long long xy = 0;
	for (int n : nums) {
		xy ^= n;
	}

	long long d = xy & -xy; ///0.....1...0

	for (int n : nums) {
		if ((n & d) == 0) ans[0] ^= n;
		else ans[1] ^= n;
	}

	return ans;
}

int main() {
	// vector<int> nums = {1, 2, 1, 3, 2, 5};
	// vector<int> nums = {0, 1};
	vector<int> nums = { -1, 0};

	auto res = singleNumber(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}