/*
https://atcoder.jp/contests/abc279/tasks/abc279_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double calc(double k, double a, double b) {

	return b * k + a / (sqrt(k + 1.0));
}

int main() {

	ll a, b;
	cin >> a >> b;

	ll lo = 0, hi = a;

	while (hi - lo > 2) {

		ll mid1 = lo + (hi - lo) / 3;
		ll mid2 = hi - (hi - lo) / 3;

		if (calc(mid1, a, b) > calc(mid2, a, b)) {
			lo = mid1;
		}
		else {
			hi = mid2;
		}
	}

	double ans = 1e20;
	for (ll i = lo; i <= hi; ++i) {
		ans = min(ans, calc(i, a, b));
	}
	cout << fixed << setprecision(10) << ans << endl;
}