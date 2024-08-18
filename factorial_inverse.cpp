#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 10;

vector<ll> fac(N + 1), inv(N + 1);

ll binarExp(ll a, ll b) {

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

void solve() {

	fac[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}

	inv[N] = binarExp(fac[N], mod - 2);

	for (int i = N - 1; i > 0; --i) {
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	}
	inv[0] = 1;
}

ll nCr(int n, int r) {

	if (r > n || r < 0) {
		return 0;
	}

	ll res = fac[n];
	res = (res * inv[r]) % mod;
	res = (res * inv[n - r]) % mod;

	return res;
}

int main() {

	solve();
	cout << nCr(3, 2) << endl;
}