/*
https://atcoder.jp/contests/abc373/tasks/abc373_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
vector<pair<int, ll>> g[N];
vector<ll> weight(N);
vector<bool> vis(N);

void bfs(int s) {

	queue<int> q;
	q.push(s);
	vis[s] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto p : g[u]) {
			int v = p.first;
			ll w = p.second;
			if (vis[v]) continue;
			weight[v] = weight[u] + w;
			vis[v] = true;
			q.push(v);
		}
	}
}


int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, -w});
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		bfs(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << weight[i] << " ";
	}
	cout << endl;
}