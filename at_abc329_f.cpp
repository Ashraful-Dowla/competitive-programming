/*
https://atcoder.jp/contests/abc329/tasks/abc329_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, set<ll>> mp;

vector<ll> vis, parent, sz;

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

		if (sz[a] < sz[b])
			swap(a, b);

		for (ll x : mp[b]) {
			mp[a].insert(x);
		}

		parent[b] = a;
		sz[a] += sz[b];
	}

}

int main() {

	int n, q;
	cin >> n >> q;

	vis.assign(n + q + 1, 0);
	parent.assign(n + q + 1, 0);
	sz.assign(n + q + 1, 0);

	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;

		mp[i].insert(x);
		vis[i] = i;
	}

	make(n + q);

	int cnt = n + 1;
	while (q--) {

		int x, y;
		cin >> x >> y;

		Union(vis[x], vis[y]);
		vis[x] = ++cnt;

		cout << mp[find(vis[y])].size() << endl;
	}

}