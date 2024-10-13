/*
https://atcoder.jp/contests/abc372/tasks/abc372_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int par[N], sz[N];
map<int, set<int>> mp;

void make(int n) {
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		mp[i].insert(i);
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		par[b] = a;
		sz[a] += sz[b];
	}

}

int main() {

	int n, q;
	cin >> n >> q;

	make(n);

	while (q--) {

		int t;
		cin >> t;

		if (t == 1) {

			int u, v;
			cin >> u >> v;

			int ru = find(u);
			int rv = find(v);

			if (ru != rv) {
				
				auto su = mp[ru];
				auto sv = mp[rv];

				Union(u, v);
				int r = find(u);

				for (int x : su) {
					mp[r].insert(x);
				}
				for (int x : sv) {
					mp[r].insert(x);
				}

				while (mp[r].size() > 10) {
					mp[r].erase(mp[r].begin());
				}
			}
		}
		else {
			int u, k;
			cin >> u >> k;

			int r = find(u);

			if (mp[r].size() < k) {
				cout << -1 << endl;
			}
			else {
				k = mp[r].size() - k + 1;
				for (int x : mp[r]) {
					k--;
					if (k == 0) {
						cout << x << endl;
						break;
					}
				}
			}
		}
	}
}