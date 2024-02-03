/*
https://atcoder.jp/contests/abc338/tasks/abc338_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;
const int N = 21;

ll dis[N][N];
ll dp[1 << N][N];

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;

		dis[u - 1][v - 1] = w;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dis[i][k] == INF || dis[k][j] == INF) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = INF;
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[1 << i][i] = 0;
	}

	for (int bit = 1; bit < (1 << n) - 1; ++bit) {

		for (int i = 0; i < n; ++i) {

			if (!(bit & (1 << i))) continue;
			if (dp[bit][i] == INF) continue;

			for (int j = 0; j < n; ++j) {

				if (bit & (1 << j)) continue;
				if (dis[i][j] == INF) continue;

				dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dis[i][j]);
			}
		}
	}

	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, dp[(1 << n) - 1][i]);
	}

	if (ans == INF) cout << "No" << endl;
	else cout << ans << endl;

}