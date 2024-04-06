/*
https://atcoder.jp/contests/abc284/tasks/abc284_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int limit = 1e6;
vector<int> graph[N];
bool vis[N];
int ans = 0;

void dfs(int v) {

	if (ans == limit) {
		return ;
	}

	vis[v] = true;
	ans++;

	for (int x : graph[v]) {
		if (vis[x]) continue;
		dfs(x);
	}

	vis[v] = false;
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

	dfs(1);
	cout << ans << endl;
}