/*
https://atcoder.jp/contests/abc320/tasks/abc320_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int n = s.size();
	bool dp[n + 5][n + 5];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = false;
		}
	}

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		dp[i][i] = true;

		if (i + 1 < n) {
			dp[i][i + 1] = s[i] == s[i + 1];

			if (dp[i][i + 1]) {
				ans = max(ans, 2);
			}
		}
	}

	for (int i = 2; i < n; ++i) {
		for (int j = 0; j + i < n; ++j) {

			int x = j;
			int y = j + i;

			dp[x][y] = dp[x + 1][y - 1] && (s[x] == s[y]);

			if (dp[x][y]) {
				ans = max(ans, y - x + 1);
			}
		}
	}

	cout << ans << endl;
}