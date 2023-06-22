/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

	stack<int> stk;
	int ans = 0;
	for (int p : prices) {

		while (!stk.empty() && stk.top() < p) {
			ans += (p - stk.top());
			stk.pop();
			break;
		}
		stk.push(p);
	}

	return ans;
}

int main() {
	// vector<int> prices = {7, 1, 5, 3, 6, 4};
	// vector<int> prices = {1, 2, 3, 4, 5};
	vector<int> prices = {7, 6, 4, 3, 1};

	cout << maxProfit(prices);
}