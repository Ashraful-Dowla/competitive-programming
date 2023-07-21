/*
https://leetcode.com/problems/house-robber-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, vector<int> &dp, int n, int idx) {

	if (idx >= n) return 0;
	if (dp[idx] != -1) return dp[idx];


	int ans = solve(nums, dp, n, idx + 2) + nums[idx];
	ans = max(ans, solve(nums, dp, n, idx + 1));

	return dp[idx] = ans;
}

int rob(vector<int>& nums) {

	int n = nums.size();

	if (n == 1) return nums[0];

	vector<int> dp1(n, -1), dp2(n, -1), dp3(n, -1);
	return max({solve(nums, dp1, n - 1, 0),
	            solve(nums, dp2, n, 1),
	            solve(nums, dp3, n - 1, 1)
	           });
}

int main() {
	// vector<int> nums = {2, 3, 2};
	// vector<int> nums = {1, 2, 3, 1};
	// vector<int> nums = {1, 2, 3};
	// vector<int> nums = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	vector<int> nums = {1};

	cout << rob(nums);
}