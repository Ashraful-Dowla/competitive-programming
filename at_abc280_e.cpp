/*
https://atcoder.jp/contests/abc280/tasks/abc280_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;

ll binaryExp(ll a, ll b) {

	ll res = 1;
	while (b) {
		if ((b & 1LL)) {
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return res;
}

int main() {


	ll n, p;
	cin >> n >> p;

	ll ans = 1, x = 1;
	ll inv = binaryExp(100, M - 2);
	ll invp = (p * inv) % M;

	for (int i = 1; i < n; ++i) {
		x = (1 - (x * invp) % M + M) % M;
		ans = (ans + x) % M;
	}

	cout << ans << endl;
}