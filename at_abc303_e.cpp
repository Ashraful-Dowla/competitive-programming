/*
https://atcoder.jp/contests/abc303/tasks/abc303_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N], level(N);
vector<bool> vis(N);
vector<int> ans;

void dfs(int v) {

	vis[v] = true;

	for (int child : graph[v]) {
		if (vis[child]) continue;
		level[child] = level[v] + 1;
		dfs(child);
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int leaf;
	for (int i = 1; i <= n; ++i) {
		if (graph[i].size() == 1) {
			leaf = i;
		}
	}

	dfs(leaf);

	for (int i = 1; i <= n; ++i) {
		// cout << level[i] << " ";

		if (level[i] % 3 == 1) {
			ans.push_back(graph[i].size());
		}
	}
	// cout << endl;

	sort(ans.begin(), ans.end());
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

}