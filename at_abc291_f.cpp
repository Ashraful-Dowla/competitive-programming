/*
https://atcoder.jp/contests/abc291/tasks/abc291_f
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int main() {

	int n, m;
	cin >> n >> m;

	string s[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '_' + s[i];
	}

	vector<int> dp0(n + 1, INF);
	dp0[1] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j - i <= m; ++j) {
			if (s[i][j - i] == '1') {
				dp0[j] = min(dp0[j], dp0[i] + 1);
			}
		}
	}

	vector<int> dp1(n + 1, INF);
	dp1[n] = 0;

	for (int i = n - 1; i >= 1; --i) {
		for (int j = i + 1; j - i <= m; ++j) {
			if (s[i][j - i] == '1') {
				dp1[i] = min(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int k = 2; k < n; ++k) {
		int ans = INF;
		for (int i = max(k - m, 1); i < k; ++i) {
			for (int j = k + 1; j - i <= m; ++j) {
				if (s[i][j - i] == '1') {
					ans = min(ans, dp0[i] + dp1[j] + 1);
				}
			}
		}

		if (ans == INF) cout << -1 << " ";
		else cout << ans << " ";
	}
	cout << endl;

}