/*
https://atcoder.jp/contests/abc350/tasks/abc350_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

vector<int> graph[N];
bool vis[N];
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

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

		Union(u, v);
	}

	map<int, ll> mp;
	for (int i = 1; i <= n; ++i) {
		mp[find(i)]++;
	}

	ll ans = 0;
	for (auto p : mp) {
		ans += (p.second * (p.second - 1)) / 2;
	}

	cout << ans - m << endl;
}