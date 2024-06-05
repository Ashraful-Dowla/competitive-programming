/*
https://atcoder.jp/contests/abc356/tasks/abc356_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll solve(ll n, int i) {

	ll p = 1LL << i;
	ll k = n / (2 * p);
	ll curr = k * p;

	ll l = n % (2 * p);
	if (l >= p) {
		curr += l - p + 1;
	}

	return curr;
}

int main() {

	ll n, m;
	cin >> n >> m;

	ll res = 0;
	for (int i = 0; i < 60; ++i) {
		if (m & (1LL << i)) {
			res += solve(n, i);
			res %= mod;
		}
	}

	cout << res << endl;
}