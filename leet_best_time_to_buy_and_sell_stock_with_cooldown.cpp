/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[5005][3];

int solve(vector<int> &prices, int idx, bool bought) {

	if (idx >= prices.size()) {
		return 0;
	}

	if (dp[idx][bought] != -1) return dp[idx][bought];

	int ans = solve(prices, idx + 1, bought);
	if (bought) {
		ans = max(ans, solve(prices, idx + 2, false) + prices[idx]);
	}
	else {
		ans = max(ans, solve(prices, idx + 1, true) - prices[idx]);
	}

	return dp[idx][bought] = ans;
}

int maxProfit(vector<int>& prices) {

	for (int i = 0; i < prices.size(); ++i) {
		dp[i][0] = dp[i][1] = -1;
	}

	return solve(prices, 0, false);
}

int main() {

	// vector<int> prices = {1, 2, 3, 0, 2};
	// vector<int> prices = {1};
	vector<int> prices = {4, 3, 2, 10, 11, 0, 11};

	cout << maxProfit(prices) << endl;
}