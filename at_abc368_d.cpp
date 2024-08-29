/*
https://atcoder.jp/contests/abc368/tasks/abc368_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> tree[N];
bool vis[N];

bool dfs(int u, int p) {

	for (int v : tree[u]) {
		if (v == p) continue;
		vis[u] |= dfs(v, u);
	}

	return vis[u];
}

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector<int> v(k);
	for (int i = 0; i < k; ++i) {
		cin >> v[i];
		vis[v[i]] = true;
	}

	dfs(v[0], -1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		// cout << vis[i] << endl;
		ans += vis[i];
	}
	cout << ans << endl;
}