/*
https://leetcode.com/problems/wiggle-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005][2];

int solve(vector<int>& nums, int val, int idx, bool type) {

	if (idx == nums.size()) return 0;
	if (dp[val][idx][type] != -1) return dp[val][idx][type];

	int len = solve(nums, val, idx + 1, type);
	if (type && nums[idx] > val) {
		len = max(len, solve(nums, nums[idx], idx + 1, false) + 1);
	}
	else if (!type && nums[idx] < val) {
		len = max(len, solve(nums, nums[idx], idx + 1, true) + 1);
	}

	return dp[val][idx][type] = len;
}

int wiggleMaxLength(vector<int>& nums) {

	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j < nums.size(); ++j) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	int len = 0;
	for (int i = 0; i < nums.size(); ++i) {
		len = max(len, solve(nums, nums[i], i + 1, true) + 1);
		len = max(len, solve(nums, nums[i], i + 1, false) + 1);
	}

	return len;
}

int main() {

	// vector<int> nums = {1, 7, 4, 9, 2, 5};
	// vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};


	cout << wiggleMaxLength(nums) << endl;
}