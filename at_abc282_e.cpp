/*
https://atcoder.jp/contests/abc282/tasks/abc282_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int parent[505], sz[505];

void make(int n) {
	for (int i = 0; i < n; ++i) {
		sz[i] = 1;
		parent[i] = i;
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

ll binaryExp(int a, int b, ll m) {

	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return res;
}


int main() {

	int n;
	ll m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<pair<ll, pair<int, int>>> v;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll res = (binaryExp(a[i], a[j], m) + binaryExp(a[j], a[i], m)) % m;
			v.push_back({res, {i, j}});
		}
	}

	sort(v.rbegin(), v.rend());

	make(n);

	ll ans = 0;
	for (auto p : v) {
		ll ct = p.first;
		int u = p.second.first;
		int v = p.second.second;

		if (find(u) == find(v)) {
			continue;
		}

		Union(u, v);
		ans += ct;
	}

	cout << ans << endl;
}