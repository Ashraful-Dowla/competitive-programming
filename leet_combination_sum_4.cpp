/*
https://leetcode.com/problems/combination-sum-iv/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1010];

int solve(vector<int>&nums, int target) {

	if (target == 0) return 1;
	if (dp[target] != -1) return dp[target];

	int cnt = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (target - nums[i] >= 0) {
			cnt += solve(nums, target - nums[i]);
		}
	}

	return dp[target] = cnt;
}

int combinationSum4(vector<int>& nums, int target) {
	memset(dp, -1, sizeof(dp));
	return solve(nums, target);
}

int main() {

	// vector<int> nums = {1, 2, 3};
	// int target = 4;

	// vector<int> nums = {9};
	// int target = 3;

	vector<int> nums = {1, 2, 3};
	int target = 32;

	cout << combinationSum4(nums, target) << endl;
}