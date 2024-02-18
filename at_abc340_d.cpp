/*
https://atcoder.jp/contests/abc340/tasks/abc340_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const ll INF = 1e15;

vector<pair<int, ll>> graph[N];

ll dijkstra(int src, int n) {
	vector<bool> vis(N, 0);
	vector<ll> dist(N, INF);

	set<pair<ll, int>> st;

	st.insert({0, src});
	dist[src] = 0;

	while (st.size() > 0) {
		auto node = *st.begin();
		int v = node.second;
		ll v_dist = node.first;
		st.erase(st.begin());

		if (vis[v]) continue;
		vis[v] = true;

		for (auto child : graph[v]) {

			int child_v = child.first;
			ll wt = child.second;

			if (dist[v] + wt < dist[child_v]) {
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}

	return dist[n - 1];
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		ll a, b;
		int x;
		cin >> a >> b >> x;

		graph[i].push_back({i + 1, a});
		graph[i].push_back({--x, b});
	}

	cout << dijkstra(0, n) << endl;
}