/*
https://leetcode.com/problems/burst-balloons/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[315][315];

int solve(vector<int>& nums, int l, int r) {

	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	int coins = 0;
	for (int i = l; i <= r; ++i) {
		coins = max(coins, nums[l - 1] * nums[i] * nums[r + 1]
		            + solve(nums, l, i - 1) + solve(nums, i + 1, r));
	}

	return dp[l][r] = coins;
}

int maxCoins(vector<int>& nums) {

	nums.emplace(nums.begin(), 1);
	nums.push_back(1);

	int n = nums.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(nums, 1, nums.size() - 2);
}

int main() {

	// vector<int> nums = {3, 1, 5, 8};
	vector<int> nums = {1, 5};
	cout << maxCoins(nums);
}