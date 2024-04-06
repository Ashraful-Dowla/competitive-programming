/*
https://atcoder.jp/contests/abc347/tasks/abc347_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {

	int a, b;
	ll c;
	cin >> a >> b >> c;

	int p = __builtin_popcountll(c);
	int rem = a + b - p;

	if (rem >= 0 && rem % 2 == 0) {

		ll x = 0, y = 0;
		for (int k = 0; k <= 60; ++k) {

			ll v = c & (1LL << k);

			if (v > 0) {
				if (a >= b) {
					x ^= (1LL << k);
					a--;
				}
				else {
					y ^= (1LL << k);
					b--;
				}
			}
		}

		for (int k = 0; k <= 60; ++k) {
			ll v = c & (1LL << k);

			if (v == 0 && a > 0 && b > 0) {
				x ^= (1LL << k);
				y ^= (1LL << k);
				a--, b--;
			}
		}

		ll xy = x ^ y;

		if (a == 0 && b == 0 && xy == c) {
			cout << x << " " << y << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
}
