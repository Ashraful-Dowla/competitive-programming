#include <bits/stdc++.h>
using namespace std;


// 7 11
// 1 2 3
// 3 1 3
// 1 4 3
// 3 4 1
// 3 5 2
// 4 5 2
// 4 6 6
// 6 7 9
// 5 7 1
// 2 3 4
// 5 2 1
// 1 7

//ans:5

const int MAX_V = 100;
const int INF = 1e9;

//s -> source
//t -> sink

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> parent;

void augment(int v, int minEdge) {

	if (v == s) {
		f = minEdge;
		return ;
	}
	else if (parent[v] != -1) {
		augment(parent[v], min(minEdge, res[parent[v]][v]));
		res[parent[v]][v] -= f;
		res[v][parent[v]] += f;
	}

}

//time complexity -> O(V*E^2)
int max_flow() {
	
	mf = 0;
	while (true) {
		f = 0;
		vector<int> dist(MAX_V, INF);
		parent.assign(MAX_V, -1);

		queue<int> q;
		q.push(s);
		dist[s] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			if (u == t) break;

			for (int v = 0; v < MAX_V; ++v) {
				if (res[u][v] > 0 && dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v);
					parent[v] = u;
				}
			}
		}

		augment(t, INF);
		if (f == 0) break;
		mf += f;
	}

	return mf;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v, cst;
		cin >> u >> v >> cst;
		res[u][v] = cst;
	}

	cin >> s >> t;

	cout << max_flow() << endl;
}