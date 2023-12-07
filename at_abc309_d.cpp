/*
https://atcoder.jp/contests/abc309/tasks/abc309_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> graph[N];
bool vis[N];
int n1, n2, m, ans, res, level[N];

void bfs(int v) {

	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int child : graph[u]) {
			if (vis[child]) continue;
			q.push(child);
			vis[child] = true;
			level[child] = level[u] + 1;
			ans = max(ans, level[child]);
		}
	}
}

int main() {

	cin >> n1 >> n2 >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(1);
	res += ans;
	ans = 0;
	bfs(n1 + n2);
	res += ans;

	cout << res + 1 << endl;
}