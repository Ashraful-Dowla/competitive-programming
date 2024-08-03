/*
https://atcoder.jp/contests/abc365/tasks/abc365_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll can(vector<ll>&v, ll x) {

	ll res = 0;
	for (ll p : v) {
		res += min(p, x);
	}

	return res;
}

int main() {

	int n;
	ll m;

	cin >> n >> m;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll lo = 0, hi = INF, ans = 0;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		if (can(v, mid) <= m) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	if (ans == INF) {
		cout << "infinite" << endl;
	}
	else {
		cout << ans << endl;
	}
}