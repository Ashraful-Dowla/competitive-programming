#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// time complexity -> O(V^2E + VE)

int main() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, ll>> graph[n + 1];

	for (int i = 0; i < m; ++i) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
	}

	vector<ll> dis(n, INT_MAX);

	dis[0] = 0;

	for (int k = 0; k < n - 1; ++k) {
		for (int u = 0; u < n; ++u) {
			for (auto v : graph[u]) {
				dis[v.first] = min(dis[v.first], dis[u] + v.second);
			}
		}
	}

	bool has_neg_cycle = false;
	for (int u = 0; u < n; ++u) {
		for (auto v : graph[u]) {
			if (dis[v.first] > dis[u] + v.second) {
				has_neg_cycle = true;
			}
		}
	}

	cout << has_neg_cycle << endl;

}