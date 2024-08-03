/*
https://atcoder.jp/contests/abc362/tasks/abc362_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 2e5 + 10;
const ll INF = 1e17 + 10;

vector<pii>graph[N];
int n, m;
ll a[N];

void dijkstra(int src) {

	vector<bool> vis(N, false);
	vector<ll> dist(N, INF);

	set<pii> st;

	st.insert({a[src], src});
	dist[src] = a[src];

	while (st.size() > 0) {

		auto node = *st.begin();
		ll v = node.second;
		st.erase(st.begin());

		if (vis[v]) continue;
		vis[v] = true;

		for (auto child : graph[v]) {

			ll child_v = child.first;
			ll wt = child.second;

			if (dist[v] + wt + a[child_v] < dist[child_v]) {
				dist[child_v] = dist[v] + wt + a[child_v];
				st.insert({dist[child_v], child_v});
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		ll x, y, wt;
		cin >> x >> y >> wt;
		graph[x].push_back({y, wt});
		graph[y].push_back({x, wt});
	}

	dijkstra(1);
}