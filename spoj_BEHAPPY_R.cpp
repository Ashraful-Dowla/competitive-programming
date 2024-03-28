/*
https://www.spoj.com/problems/BEHAPPY/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	while (true) {
		int m, n;
		cin >> m >> n;

		if (m == 0 && n == 0) {
			break;
		}

		int a[m + 1], b[m + 1];
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (int i = 1; i <= m; ++i) {
			cin >> a[i] >> b[i];
		}

		dp[0][0] = 1;

		for (int i = 1; i <= m; ++i) {
			for (int nn = 0; nn <= n; ++nn) {
				for (int j = a[i]; j <= b[i]; ++j) {
					if (nn - j >= 0) {
						dp[i][nn] += dp[i - 1][nn - j];
					}
				}
			}
		}

		cout << dp[m][n] << endl;
	}
}