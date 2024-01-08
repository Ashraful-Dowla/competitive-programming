/*
https://atcoder.jp/contests/abc335/tasks/abc335_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int INF = -1e6;

int a[N], n, m, dp[N], parent[N], sz[N];
vector<int> graph[N];
bool vis[N];

void make(int n) {
	for (int i = 1; i <= n; ++i) {
		dp[i] = INF;
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

void dfs(int v) {

	vis[v] = true;
	int rv = find(v);

	if (v == n) {
		dp[rv] = max(dp[rv], 1);
		return ;
	}

	for (int child : graph[v]) {

		if (!vis[child] && a[v] <= a[child]) {
			dfs(child);
		}

		int rchild = find(child);
		if (a[v] <= a[child]) {
			dp[rv] = max(dp[rv], dp[rchild] + (a[v] < a[child]));
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	make(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

		if (a[u] == a[v]) {
			Union(u, v);
		}
	}

	dfs(1);

	int root = find(1);
	cout << max(dp[root], 0) << endl;
}