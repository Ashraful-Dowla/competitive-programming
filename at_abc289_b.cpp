/*
https://atcoder.jp/contests/abc289/tasks/abc289_b
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];
bool vis[N];
vector<int> ans;

void dfs(int v) {

	vis[v] = true;
	for (int child : graph[v]) {
		if (vis[child]) continue;
		dfs(child);
		ans.push_back(child);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u;
		cin >> u;
		graph[u].push_back(u + 1);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
			ans.push_back(i);
		}
	}

	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}