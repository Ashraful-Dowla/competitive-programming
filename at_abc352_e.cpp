/*
https://atcoder.jp/contests/abc352/tasks/abc352_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int parent[N], sz[N];
vector<int> graph[N];

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
		if (sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> k(m);
	vector<pair<int, int>> c(m);

	for (int i = 0; i < m; ++i) {

		cin >> k[i] >> c[i].first;

		for (int j = 0; j < k[i]; ++j) {
			int u;
			cin >> u;
			graph[i].push_back(u);
		}

		c[i].second = i;
	}


	sort(c.begin(), c.end());

	make(n);

	ll cost = 0;

	for (auto p : c) {
		int i = p.second;
		int wt = p.first;
		for (int j = 1; j < k[i]; ++j) {
			int u = graph[i][0], v = graph[i][j];
			if (find(u) == find(v)) {
				continue;
			}
			Union(u, v);
			cost += wt;
		}
	}

	cout << (sz[find(1)] == n ? cost : -1) << endl;
}