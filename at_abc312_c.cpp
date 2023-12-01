/*
https://atcoder.jp/contests/abc312/tasks/abc312_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can(vector<ll>& a, vector<ll>& b, ll mid) {

	int n = 0, m = 0;

	for (ll x : a) {
		if (x <= mid) {
			n++;
		}
	}

	for (ll x : b) {
		if (x >= mid) {
			m++;
		}
	}

	return n >= m;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<ll> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	ll lo = 0, hi = 1e9 + 10;

	ll ans = 1e10;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		if (can(a, b, mid)) {
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << ans << endl;
}