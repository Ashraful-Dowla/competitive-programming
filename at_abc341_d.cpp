/*
https://atcoder.jp/contests/abc341/tasks/abc341_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n, m, k;
	cin >> n >> m >> k;

	ll lo = 0, hi = 2e18;

	ll lcm = (n * m) / __gcd(n, m);

	ll ans;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll x = (mid / n) + (mid / m) - 2 * (mid / lcm);

		if (x < k) {
			lo = mid + 1;
		}
		else {
			ans = mid;
			hi = mid - 1;
		}
	}

	cout << ans << endl;
}