/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

	stack<pair<int, int>> stk;
	for (int p : prices) {

		if (stk.empty()) stk.push({p, p});
		else {
			int mn = min(p, stk.top().second);
			stk.push({p, mn});
		}
	}

	int profit = 0;

	while (!stk.empty()) {
		auto p = stk.top();
		stk.pop();
		profit = max(profit, p.first - p.second);
	}

	return profit;
}

int main() {
	// vector<int> prices = {7, 1, 5, 3, 6, 4};
	// vector<int> prices = {7, 6, 4, 3, 1};
	// vector<int> prices = {3, 2, 6, 5, 0, 3};
	// vector<int> prices = {6, 1, 3, 2, 4, 7};
	vector<int> prices = {2, 4, 1};

	cout << maxProfit(prices);
}