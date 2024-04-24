/*
https://atcoder.jp/contests/abc349/tasks/abc349_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;

int main() {

	ll l, r;
	cin >> l >> r;

	vector<pll> ans;

	while (l < r) {
		ll p = 0;
		for (ll i = 0; i <= 60; ++i) {
			ll d = 1LL << i;
			if (l % d == 0 && d * (1 + l / d) <= r) {
				p = i;
			}
		}
		ll dd = 1LL << p;
		ll q = dd * (1 + l / dd);
		ans.push_back({l, q});
		l = q;
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}