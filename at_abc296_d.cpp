/*
https://atcoder.jp/contests/abc296/tasks/abc296_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX = 1e6;

int main() {

	ll n, m;
	cin >> n >> m;

	ll ans = 1e18;
	for (ll b = 1; b <= min(n, MX); ++b) {
		ll a = m / b;
		if (a * b >= m && a <= n) {
			ans = min(ans, a * b);
		}
		a++;
		if (a * b >= m && a <= n) {
			ans = min(ans, a * b);
		}
	}

	cout << (ans == 1e18 ? -1 : ans) << endl;
}