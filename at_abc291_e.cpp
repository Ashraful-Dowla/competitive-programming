/*
https://atcoder.jp/contests/abc291/tasks/abc291_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N], height(N, -1);

int dfs(int v) {

	if (height[v] != -1) {
		return height[v];
	}

	height[v] = 0;
	for (int child : graph[v]) {
		height[v] = max(height[v], dfs(child) + 1);
	}

	return height[v];
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	int d = 0;
	for (int i = 1; i <= n; ++i) {
		d = max(d, dfs(i));
	}

	if (d == n - 1) {
		cout << "Yes" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << n - height[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
}