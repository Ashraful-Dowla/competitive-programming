#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N], rev[N];
bool vis[N], vis2[N];
stack<int> stk;

// time complexity -> O(V+E)

void dfs(int u) {

	vis[u] = true;
	for (int v : graph[u]) {
		if (vis[v]) continue;
		dfs(v);
	}

	stk.push(u);
}

void dfs2(int u) {

	cout << u << " ";
	vis2[u] = true;
	for (int v : rev[u]) {
		if (vis2[v]) continue;
		dfs2(v);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		rev[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		dfs(i);
	}

	while (!stk.empty()) {
		if (!vis2[stk.top()]) {
			dfs2(stk.top());
			cout << endl;
		}
		stk.pop();
	}
}