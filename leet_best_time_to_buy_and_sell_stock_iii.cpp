/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/
#include <bits/stdc++.h>
using namespace std;

//state 0 -> no bought
//state 1 -> bought

int dp[2][3][100005];

int solve(vector<int> &prices, int state, int trans, int day) {

	if (trans == 2 || day == prices.size()) return 0;
	if (dp[state][trans][day] != -1) return dp[state][trans][day];

	int sum = solve(prices, state, trans, day + 1); //skip
	if (state == 0) {
		//buy
		sum = max(sum, solve(prices, 1, trans, day + 1) - prices[day]);
	}
	else {
		//sell
		sum = max(sum, solve(prices, 0, trans + 1, day + 1) + prices[day]);
	}

	return dp[state][trans][day] = sum;
}

int maxProfit(vector<int>& prices) {

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < prices.size(); ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	return solve(prices, 0, 0, 0);
}

int main() {
	// vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	// vector<int> prices = {1, 2, 3, 4, 5};
	vector<int> prices = {7, 6, 4, 3, 1};
	// vector<int> prices = {6, 1, 3, 2, 4, 7};

	cout << maxProfit(prices);
}