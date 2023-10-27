#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pr>graph[N];
int n, m;

// time complexity -> O(V + ElogV)

void dijkstra(int src) {
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);

	set<pr> st;

	st.insert({0, src});
	dist[src] = 0;

	while (st.size() > 0) {
		auto node = *st.begin();
		int v = node.second;
		int v_dist = node.first;

		st.erase(st.begin());

		if (vis[v]) continue;
		vis[v] = 1;

		for (auto child : graph[v]) {

			int child_v = child.first;
			int wt = child.second;

			if (dist[v] + wt < dist[child_v]) {
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << i << " " << dist[i] << endl;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, wt;
		cin >> x >> y >> wt;
		graph[x].push_back({y, wt});
	}
	dijkstra(1);
}