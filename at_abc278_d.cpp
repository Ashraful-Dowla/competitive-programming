/*
https://atcoder.jp/contests/abc278/tasks/abc278_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<int, bool> mp;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		v[i] = x;
		mp[i] = true;
	}

	int q;
	cin >> q;

	ll p = 0;
	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			cin >> p;
			mp.clear();
		}
		else if (t == 2) {
			int i;
			ll x;
			cin >> i >> x;

			if (mp.find(i) == mp.end()) {
				v[i] = p + x;
				mp[i] = true;
			}
			else {
				v[i] += x;
			}
		}
		else {
			int i;
			cin >> i;

			if (mp.find(i) == mp.end()) {
				v[i] = p;
				mp[i] = true;
			}

			cout << v[i] << endl;
		}
	}
}