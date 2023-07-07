/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][105][5];

int solve(vector<int>& prices, int idx, int k, bool bought) {

	if (k == 0 || idx == prices.size()) return 0;
	if (dp[idx][k][bought] != -1) return dp[idx][k][bought];

	int price = solve(prices, idx + 1, k, bought);
	if (bought) {
		price = max(price, solve(prices, idx + 1, k - 1, false) + prices[idx]);
	}
	else {
		price = max(price, solve(prices, idx + 1, k, true) - prices[idx]);
	}

	return dp[idx][k][bought] = price;
}

int maxProfit(int k, vector<int>& prices) {

	for (int i = 0; i <= prices.size(); ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int l = 0; l <= 2; ++l) {
				dp[i][j][l] = -1;
			}
		}
	}

	return solve(prices, 0, k, false);
}

int main() {

	int k = 2;
	vector<int> prices = {3, 2, 6, 5, 0, 3};

	// int k = 2;
	// vector<int> prices = {2, 4, 1};

	cout << maxProfit(k, prices);
}