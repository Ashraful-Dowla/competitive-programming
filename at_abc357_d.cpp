/*
https://atcoder.jp/contests/abc357/tasks/abc357_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll binExp(ll a, ll b) {

	ll res = 1;
	while (b) {
		if (b & 1LL) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}

	return res;
}

int main() {

	ll n;
	cin >> n;

	ll r = 1, x = n;
	while (x) {
		x /= 10;
		r  = (r * 10) % mod;
	}

	ll inv = binExp(r - 1, mod - 2);
	ll ans = (binExp(r, n) - 1 + mod) % mod;

	n %= mod;

	ans = (ans * inv) % mod;
	ans = (ans * n) % mod;

	cout << ans << endl;
}