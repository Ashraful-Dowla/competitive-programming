/*
https://atcoder.jp/contests/abc277/tasks/abc277_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<pair<int, int>> graph[N];
bool mark[N];
int level[N][2];

int bfs(int s, int n) {

	for (int i = 1; i <= n; ++i) {
		level[i][0] = level[i][1] = 1e7;
	}

	queue<pair<int, int>> q;
	q.push({s, 1});

	level[s][1] = 0;

	while (!q.empty()) {

		int u = q.front().first;
		bool t = q.front().second;
		q.pop();

		for (auto p : graph[u]) {

			int v = p.first;
			bool k = p.second;

			if (level[u][t] + 1 < level[v][k] && k == t) {
				level[v][k] = level[u][t] + 1;
				q.push({v, k});
			}
			if (mark[u]) {
				level[u][t ^ 1] = min(level[u][t ^ 1], level[u][t]);
				if (level[u][t ^ 1] + 1 < level[v][k] && k == t ^ 1) {
					level[v][k] = level[u][t ^ 1] + 1;
					q.push({v, k});
				}
			}
		}
	}

	int res = min(level[n][0], level[n][1]);

	return res == 1e7 ? -1 : res;
}

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int u, v, p;
		cin >> u >> v >> p;

		graph[u].push_back({v, p});
		graph[v].push_back({u, p});
	}

	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		mark[x] = true;
	}

	cout << bfs(1, n) << endl;
}