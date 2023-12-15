/*
https://atcoder.jp/contests/abc305/tasks/abc305_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, k;

	cin >> n >> m >> k;

	vector<int> graph[n + 1];

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	multiset<pair<int, int>> ms;

	vector<int> dis(n + 1, -1);

	for (int i = 0; i < k; ++i) {
		int p, h;
		cin >> p >> h;

		if (dis[p] < h) {
			dis[p] = h;
			ms.insert({dis[p], p});
		}
	}

	while (ms.size()) {
		auto p = (--ms.end());
		ms.erase(p);

		int u = p->second;
		int cost = p->first;

		if (cost == dis[u]) {
			for (int v : graph[u]) {
				if (dis[v] < dis[u] - 1) {
					dis[v] = dis[u] - 1;
					ms.insert({dis[v], v});
				}
			}
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (dis[i] >= 0) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}