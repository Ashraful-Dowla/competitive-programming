/*
https://atcoder.jp/contests/abc292/tasks/abc292_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
vector<int> graph[N];
int parent[N], sz[N];

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

	vector<int> u(m), v(m);
	for (int i = 0; i < m; ++i) {
		cin >> u[i] >> v[i];
	}

	make(n);

	for (int i = 0; i < m; ++i) {
		Union(u[i], v[i]);
	}

	vector<int> nodes(N), edges(N);

	for (int i = 1; i <= n; ++i) {
		nodes[find(i)]++;
	}

	for (int i = 0; i < m; ++i) {
		edges[find(u[i])]++;
	}

	if (nodes == edges) cout << "Yes" << endl;
	else cout << "No" << endl;
}