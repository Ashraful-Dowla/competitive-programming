/*
https://atcoder.jp/contests/abc317/tasks/abc317_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll weight[15][15], n, m;
vector<int> graph[15];

ll solve(int i, int taken) {

	if (__builtin_popcount(taken) == n) {
		return 0;
	}

	ll ans = 0;
	for (int j : graph[i]) {

		if (taken & (1 << j))
			continue;

		ans = max(ans, solve(j, taken | (1 << j)) + weight[i][j]);
	}

	return ans;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		weight[u][v] = weight[v][u] = w;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, solve(i, 1 << i));
	}

	cout << ans << endl;
}