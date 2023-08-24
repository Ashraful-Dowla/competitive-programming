/*
https://leetcode.com/problems/coin-change/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[10005][15];

int solve(vector<int>& coins, int amount, int idx) {

	if (amount == 0) return 0;
	if (idx < 0) return 1e5;
	if (dp[amount][idx] != -1) return dp[amount][idx];

	int ans = 1e5;
	if (amount - coins[idx] >= 0) {
		ans = min(ans, solve(coins, amount - coins[idx], idx) + 1);
	}
	ans = min(ans, solve(coins, amount, idx - 1));

	return dp[amount][idx] = ans;
}

int coinChange(vector<int>& coins, int amount) {

	sort(coins.begin(), coins.end());

	int n = coins.size();
	for (int i = 0; i <= amount; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = -1;
		}
	}

	int res = solve(coins, amount, n - 1);

	return res == 1e5 ? -1 : res;
}

int main() {

	vector<int> coins = {1, 2, 5};
	int amount = 11;

	// vector<int> coins = {2};
	// int amount = 3;

	// vector<int> coins = {1};
	// int amount = 0;

	cout << coinChange(coins, amount);
}