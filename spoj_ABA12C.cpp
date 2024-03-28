/*
https://www.spoj.com/problems/ABA12C/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e6;

int price[N], dp[N];

int solve(int k, int kg) {

	if (kg == 0) {
		return 0;
	}
	if (dp[kg] != -1) {
		return dp[kg];
	}

	int ans = INF;
	for (int i = 1; i <= k; ++i) {
		if (price[i] != -1 && kg >= i) {
			ans = min(ans, solve(k, kg - i) + price[i]);
		}
	}

	return dp[kg] = ans;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= k; ++i) {
			cin >> price[i];
		}

		for (int i = 0; i <= k; ++i) {
			dp[i] = -1;
		}


		int res = solve(k, k);
		cout << (res == INF ? -1 : res) << endl;
	}
}