/*
https://atcoder.jp/contests/abc330/tasks/abc330_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll d, dd;
	cin >> d;

	ll ans = 1e15;
	for (ll y = 0; y * y <= d; ++y) {
		ll x = sqrtl(abs(d - y * y));
		ans = min(ans, abs(x * x + y * y - d));
		x++;
		ans = min(ans, abs(x * x + y * y - d));
	}

	cout << ans << endl;
}