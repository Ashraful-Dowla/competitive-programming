/*
https://atcoder.jp/contests/abc305/tasks/abc305_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int sz = (n + 1) / 2;
	vector<ll> down(sz, 0), up(sz, 0), pf(sz, 0);

	for (int i = 1, j = 1; i + 1 < n; i += 2, j++) {
		down[j] = v[i];
		up[j] = v[i + 1];
	}

	for (int i = 1; i < sz; ++i) {
		pf[i] = pf[i - 1] + up[i] - down[i];
	}

	int q;
	cin >> q;

	while (q--) {
		ll l, r;
		cin >> l >> r;

		auto it = upper_bound(down.begin(), down.end(), l);

		int lo;
		if (it == down.end()) {
			lo = sz - 1;
		}
		else {
			lo = it - down.begin();
		}

		if (l < up[lo - 1]) {
			lo--;
		}

		it = lower_bound(up.begin(), up.end(), r);

		int hi;
		if (it == up.end()) {
			hi = sz - 1;
		}
		else {
			hi = it - up.begin();
		}

		if (r < down[hi]) {
			hi--;
		}

		if (lo > hi) {
			cout << 0 << endl;
		}
		else {
			ll sum = pf[hi] - pf[lo - 1];

			if (l > down[lo]) {
				sum -= (l - down[lo]);
			}

			if (r < up[hi]) {
				sum -= (up[hi] - r);
			}

			cout << sum << endl;
		}
	}
}