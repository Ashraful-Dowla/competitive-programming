/*
https://atcoder.jp/contests/abc345/tasks/abc345_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<pair<int, int>> graph[N];
vector<int> ans;
bool vis[N], lamp[N];
int n, m, k, on;

void dfs(int v) {

	vis[v] = true;
	for (auto p : graph[v]) {

		int child = p.first;
		int idx = p.second;

		if (vis[child]) {
			continue;
		}
		dfs(child);

		if (!lamp[child] && on < k) {
			on -= lamp[child] + lamp[v];
			lamp[child] ^= 1, lamp[v] ^= 1;
			on += lamp[child] + lamp[v];
			ans.push_back(idx);
		}
	}
}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back({v, i + 1});
		graph[v].push_back({u, i + 1});
	}

	if (k % 2) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		dfs(i);
	}

	if (on == k) {
		cout << "Yes" << endl;
		cout << ans.size() << endl;
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
}