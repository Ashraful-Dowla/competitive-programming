/*
https://atcoder.jp/contests/abc304/tasks/abc304_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll w, h;
	cin >> w >> h;

	int n;
	cin >> n;

	ll p[n], q[n];

	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> q[i];
	}

	int A;
	cin >> A;

	vector<ll> a(A + 1);
	for (int i = 0; i < A; ++i) {
		cin >> a[i];
	}

	a[A] = w;

	int B;
	cin >> B;

	vector<ll> b(B + 1);

	for (int i = 0; i < B; ++i) {
		cin >> b[i];
	}

	b[B] = h;

	map<pair<ll, ll>, ll> mp;
	for (int i = 0; i < n; ++i) {
		ll x = *lower_bound(a.begin(), a.end(), p[i]);
		ll y = *lower_bound(b.begin(), b.end(), q[i]);

		mp[ {x, y}]++;
	}

	ll mx = 0;
	for (auto p : mp) {
		mx = max(mx, p.second);
	}

	ll mn = 1e18;
	if (mp.size() == (A + 1) * 1LL * (B + 1)) {
		for (auto p : mp) {
			mn = min(mn, p.second);
		}
	}
	else {
		mn = 0;
	}

	cout << mn << " " << mx << endl;
}