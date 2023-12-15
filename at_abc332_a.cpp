/*
https://atcoder.jp/contests/abc332/tasks/abc332_a
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	ll s, k;
	cin >> n >> s >> k;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll p, q;
		cin >> p >> q;

		sum += p * q;
	}

	if (sum >= s) cout << sum << endl;
	else cout << sum + k << endl;
}