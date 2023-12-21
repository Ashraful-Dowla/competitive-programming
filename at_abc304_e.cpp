/*
https://atcoder.jp/contests/abc304/tasks/abc304_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int parent[N], sz[N];
vector<int> graph[N];
vector<set<int>> mark(N);

void make(int n) {
	for (int i = 1; i <= n; ++i) {
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

int main() {

	int n, m;
	cin >> n >> m;

	make(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

		Union(u, v);
	}

	int k;
	cin >> k;


	for (int i = 0; i < k; ++i) {
		int u, v;
		cin >> u >> v;

		u = find(u);
		v = find(v);

		mark[v].insert(u);
		mark[u].insert(v);
	}

	int q;
	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;

		u = find(u);
		v = find(v);

		if (mark[v].find(u) != mark[v].end()) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
}