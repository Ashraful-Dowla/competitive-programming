/*
https://atcoder.jp/contests/abc287/tasks/abc287_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];

bool taken[N];

bool bfs(int s, int n) {

	queue<int> q;
	q.push(s);

	taken[s] = true;

	while (!q.empty()) {+

		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (taken[v]) continue;
			q.push(v);
			taken[v] = true;
		}
	}


	for (int i = 1; i <= n; ++i) {
		if (!taken[i]) {
			return false;
		}
	}

	return true;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (m != n - 1) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (graph[i].size() > 2) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << (bfs(1, n) ? "Yes" : "No") << endl;
}