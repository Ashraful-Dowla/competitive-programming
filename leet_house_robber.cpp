/*
https://leetcode.com/problems/house-robber/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105];

int solve(vector<int>&nums, int idx) {

	if (idx >= nums.size()) return 0;
	if (dp[idx] != -1) return dp[idx];

	int ans = solve(nums, idx + 2) + nums[idx];
	ans = max(ans, solve(nums, idx + 1));

	return dp[idx] = ans;

}

int rob(vector<int>& nums) {

	for (int i = 0; i < nums.size(); ++i) {
		dp[i] = -1;
	}
	return solve(nums, 0);
}

int main() {

	vector<int> nums = {1, 2, 3, 1};
	// vector<int> nums = {2, 7, 9, 3, 1};

	cout << rob(nums);
}