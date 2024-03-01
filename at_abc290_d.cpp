/*
https://atcoder.jp/contests/abc290/tasks/abc290_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int t;
	cin >> t;

	while (t--) {
		ll n, d, k;
		cin >> n >> d >> k;

		ll a = n / __gcd(n, d);

		cout << (k - 1) / a + ((k - 1)*d) % n << endl;
	}
}