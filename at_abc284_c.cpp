/*
https://atcoder.jp/contests/abc284/tasks/abc284_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> graph[N];
bool vis[N];

void dfs(int v) {

	vis[v] = true;

	for (int child : graph[v]) {
		if (vis[child]) continue;
		dfs(child);
	}
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

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans << endl;
}