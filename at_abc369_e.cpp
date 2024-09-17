/*
https://atcoder.jp/contests/abc369/tasks/abc369_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

struct node
{
	int u, v;
	ll w;
};

int main() {

	int n, m;
	cin >> n >> m;

	vector<node> edges(m + 1);
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1e16));

	for (int i = 1; i <= m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edges[i] = {u, v, w};
		dp[u][v] = dp[v][u] = min(dp[u][v], w);
	}

	for (int i = 1; i <= n; ++i) {
		dp[i][i] = 0;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	int q;
	cin >> q;

	while (q--) {

		int k;
		cin >> k;

		vector<int> b(k);
		for (int i = 0; i < k; ++i) {
			cin >> b[i];
		}

		sort(b.begin(), b.end());

		ll ans = 1e16;

		do {

			pli c1 = {0, 1}, c2 = {0, 1};

			for (int e : b) {
				int u = edges[e].u, v = edges[e].v;
				ll w = edges[e].w;

				pli nc1 = {1e16, u}, nc2 = {1e16, v};

				nc1.first = w + min(c1.first + dp[c1.second][v], c2.first + dp[c2.second][v]);
				nc2.first = w + min(c1.first + dp[c1.second][u], c2.first + dp[c2.second][u]);

				c1 = nc1;
				c2 = nc2;

			}

			ans = min(ans, c1.first + dp[c1.second][n]);
			ans = min(ans, c2.first + dp[c2.second][n]);

		} while (next_permutation(b.begin(), b.end()));

		cout << ans << endl;
	}
}