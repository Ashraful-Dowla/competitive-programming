/*
https://atcoder.jp/contests/abc292/tasks/abc292_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> graph[n + 1];

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		
		vector<bool> vis(n + 1, false);

		vis[i] = true;
		queue<int> q;
		q.push(i);

		while (!q.empty()) {

			int v = q.front();
			q.pop();

			for (int child : graph[v]) {
				if (vis[child]) continue;
				vis[child] = true;
				q.push(child);
				ans++;
			}
		}
	}

	cout << ans - m << endl;
}