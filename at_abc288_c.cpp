/*
https://atcoder.jp/contests/abc288/tasks/abc288_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
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

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		if (find(u) == find(v)) {
			ans++;
		}
		else {
			Union(u, v);
		}
	}

	cout << ans << endl;
}
