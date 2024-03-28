/*
https://www.spoj.com/problems/BEHAPPY/
*/
#include <bits/stdc++.h>
using namespace std;

int a[25], b[25], m, dp[25][105];

int solve(int i, int n) {

	if (i == m) {
		return n == 0;
	}
	if (dp[i][n] != -1) {
		return dp[i][n];
	}

	int ans = 0;
	for (int j = a[i]; j <= b[i]; ++j) {
		if (n - j >= 0) {
			ans += solve(i + 1, n - j);
		}
	}

	return dp[i][n] = ans;
}

int main() {

	while (true) {
		int n;
		cin >> m >> n;

		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; ++i) {
			cin >> a[i] >> b[i];
		}

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				dp[i][j] = -1;
			}
		}

		cout << solve(0, n) << endl;
	}
}