/*
https://atcoder.jp/contests/abc338/tasks/abc338_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll q[n], a[n], b[n];


	for (int i = 0; i < n; ++i) {
		cin >> q[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	ll ans = 0;
	for (ll ta = 0; ta <= 1e6; ++ta) {

		ll tb = 1e9;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (q[i] >= a[i]*ta) {
				if (b[i] == 0) continue;
				ll r = (q[i] - a[i] * ta) / b[i];
				tb = min(tb, r);
			}
			else {
				ok = false;
				break;
			}
		}

		if (ok) {
			ans = max(ans, ta + tb);
		}
	}

	cout << ans << endl;
}