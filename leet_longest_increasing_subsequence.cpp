/*
https://leetcode.com/problems/longest-increasing-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[3000];

int solve(vector<int>& nums, int idx) {

	if (idx == nums.size()) return 0;
	if (dp[idx] != -1) return dp[idx];

	int lis = 0;
	for (int i = idx; i < nums.size(); ++i) {
		if (nums[i] > nums[idx]) {
			lis = max(lis, solve(nums, i) + 1);
		}
	}

	return dp[idx] = lis;
}

int lengthOfLIS(vector<int>& nums) {

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < nums.size(); ++i) {
		ans = max(ans, solve(nums, i) + 1);
	}
	return ans;
}

int main() {

	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	// vector<int> nums = {0, 1, 0, 3, 2, 3};
	// vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
	cout << lengthOfLIS(nums);
}