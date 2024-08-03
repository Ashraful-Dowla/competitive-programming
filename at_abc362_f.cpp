/*
https://atcoder.jp/contests/abc362/tasks/abc362_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> tree[N], sz(N, 0), ord;
int n;

int dfs(int u, int p) {

	sz[u] = 1;
	for (int v : tree[u]) {
		if (v == p) continue;
		sz[u] += dfs(v, u);
	}

	return sz[u];
}

int centroid(int u, int p) {

	for (int v : tree[u]) {
		if (v != p && sz[v] > n / 2) {
			return centroid(v, u);
		}
	}

	return u;
}

void dfs2(int u, int p) {

	for (int v : tree[u]) {
		if (v == p) continue;
		dfs2(v, u);
	}

	ord.push_back(u);
}

int main() {

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);
	int c = centroid(1, 0);
	dfs2(c, 0);

	vector<pair<int, int>> ans;
	for (int i = 0; i < n / 2; ++i) {
		ans.push_back({ord[i], ord[i + n / 2]});
	}

	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}