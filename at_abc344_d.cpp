/*
https://atcoder.jp/contests/abc344/tasks/abc344_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string t;
	cin >> t;

	int tsz = t.size();
	t = "#" + t;

	int n;
	cin >> n;

	int dp[n + 2][tsz + 2];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= tsz; ++j) {
			dp[i][j] = 1e8;
		}
	}

	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;

		for (int j = 0; j <= tsz; ++j) {
			dp[i][j] = dp[i - 1][j];
		}

		for (int j = 0; j < m; ++j) {
			string s;
			cin >> s;

			int sz = s.size();
			for (int k = 1; k + sz - 1 <= tsz; ++k) {
				if (t.substr(k, sz) == s) {
					dp[i][k + sz - 1] = min(dp[i][k + sz - 1], dp[i - 1][k - 1] + 1);
				}
			}
		}
	}

	if (dp[n][tsz] == 1e8) cout << -1 << endl;
	else cout << dp[n][tsz] << endl;
}