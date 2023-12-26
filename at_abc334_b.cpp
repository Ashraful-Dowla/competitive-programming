/*
https://atcoder.jp/contests/abc334/tasks/abc334_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll a, m, l, r;
	cin >> a >> m >> l >> r;

	ll kl = (l - a) / m;
	ll kr = (r - a) / m;

	if (a + kl * m < l) {
		kl++;
	}

	if (a + kr * m > r) {
		kr--;
	}

	ll first = a + kl * m;
	ll second = a + kr * m;

	ll ans = 1 + (second - first) / m;

	cout << ans << endl;
}