/*
https://atcoder.jp/contests/abc293/tasks/abc293_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N], deg(N);
bool vis[N];

bool bfs(int v) {

	vis[v] = true;
	queue<int>q;
	q.push(v);

	bool f = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (deg[u] != 2) f = false;
		for (int child : graph[u]) {
			if (!vis[child]) {
				vis[child] = true;
				q.push(child);
			}
		}
	}

	return f;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, c;
		char b, d;
		cin >> a >> b >> c >> d;

		a--, c--;
		graph[a].push_back(c);
		graph[c].push_back(a);

		deg[a]++, deg[c]++;
	}

	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			if (bfs(i)) x++;
			else y++;
		}
	}

	cout << x << " " << y << endl;
}