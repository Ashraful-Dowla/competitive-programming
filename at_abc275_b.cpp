/*
https://atcoder.jp/contests/abc275/tasks/abc275_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

int main() {

	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	ll res1 = a % mod;
	res1 = (res1 * (b % mod)) % mod;
	res1 = (res1 * (c % mod)) % mod;

	ll res2 = d % mod;
	res2 = (res2 * (e % mod)) % mod;
	res2 = (res2 * (f % mod)) % mod;

	cout << (res1 - res2 + mod) % mod << endl;
}