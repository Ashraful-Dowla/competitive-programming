/*
https://atcoder.jp/contests/abc360/tasks/abc360_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll binaryExp(ll a, ll b, ll p) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

ll modInverse(ll a, ll p) {
	return binaryExp(a, p - 2, p);
}

int main() {
	ll n, k;
	cin >> n >> k;

	ll inv_nsq = modInverse((n * n) % mod, mod); // (n^2)^(-1) % mod
	ll inv_n_1 = modInverse(n - 1, mod); // (n-1)^(-1) % mod

	ll p1 = 1;
	for (int i = 1; i <= k; ++i) {

		ll newP1 = (p1 * inv_nsq) % mod; // p1/n^2
		newP1 = (newP1 + (p1 * ((n - 1) * (n - 1) % mod) % mod * inv_nsq % mod) % mod) % mod; // p1*(n-1)^2/n^2

		ll pj = ((1 - p1 + mod) % mod * inv_n_1) % mod; // pj = (1-p1)/(n-1)

		ll newPj = ((pj * inv_nsq) % mod * (n - 1) % mod) % mod; // (pj/n^2)*(n-1)
		newP1 = (newP1 + 2 * newPj % mod) % mod;

		p1 = newP1;
	}

	ll sum = n * (n + 1) / 2 - 1;
	sum %= mod;

	ll ans = p1;
	ll pj = ((1 - p1 + mod) % mod * inv_n_1) % mod;

	ans = (ans + (pj * sum) % mod) % mod;

	cout << ans << endl;
}