/*
https://atcoder.jp/contests/abc280/tasks/abc280_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll k;
	cin >> k;

	ll ans = 1;
	for (ll i = 2; i * i <= k; ++i) {

		ll a = 0;
		while (k % i == 0) {
			k /= i;
			a++;
		}

		ll n = 0;
		while (a > 0) {
			n += i;
			ll x = n;

			while (a > 0 && x % i == 0) {
				x /= i;
				a--;
			}
		}

		ans = max(ans, n);
	}

	ans = max(ans, k);

	cout << ans << endl;
}