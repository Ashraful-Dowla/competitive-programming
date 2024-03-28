/*
https://atcoder.jp/contests/abc346/tasks/abc346_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll k;
	cin >> n >> k;

	ll ans = k * (k + 1);
	ans /= 2;

	map<ll, bool> taken;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;

		if (!taken[x] && x >= 1 && x <= k) {
			ans -= x;
			taken[x] = true;
		}
	}

	cout << ans << endl;
}