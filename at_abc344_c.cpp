/*
https://atcoder.jp/contests/abc344/tasks/abc344_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	vector<ll> b(m);

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	int l;
	cin >> l;
	vector<ll> c(l);

	for (int i = 0; i < l; ++i) {
		cin >> c[i];
	}

	map<ll, bool> mp;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < l; ++k) {
				mp[a[i] + b[j] + c[k]] = true;
			}
		}
	}

	int q;
	cin >> q;

	while (q--) {
		ll x;
		cin >> x;

		if (mp[x]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}