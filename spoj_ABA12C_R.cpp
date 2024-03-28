/*
https://www.spoj.com/problems/ABA12C/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e6;

int price[N], dp[N];

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= k; ++i) {
			cin >> price[i];
			dp[i] = INF;
		}

		dp[0] = 0;

		for (int kg = 1; kg <= k; ++kg) {
			for (int i = 1; i <= k; ++i) {
				if (price[i] != -1 && kg >= i) {
					dp[kg] = min(dp[kg], dp[kg - i] + price[i]);
				}
			}
		}

		cout << (dp[k] == INF ? -1 : dp[k]) << endl;
	}
}