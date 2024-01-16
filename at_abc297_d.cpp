/*
https://atcoder.jp/contests/abc297/tasks/abc297_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll a, b;
	cin >> a >> b;

	ll res = 0;

	while (a % b > 0 && b % a > 0) {
		if (a > b) {
			ll d = a / b;
			a = a - d * b;
			res += d;
		}
		else {
			ll d = b / a;
			b = b - a * d;
			res += d;
		}
	}

	if (a % b == 0) {
		cout << res + (a / b) - 1 << endl;
	}
	else {
		cout << res + (b / a) - 1 << endl;
	}
}