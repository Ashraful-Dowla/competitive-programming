/*
https://atcoder.jp/contests/abc358/tasks/abc358_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 26;
const int N = 2e6 + 10;
const ll mod = 998244353;

ll fact[N + 1], inv[N + 1];

ll binaryExp(ll a, ll b) {

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

ll ncr(int n, int r) {

	if (n < 0 || r < 0 || n - r < 0) {
		return 0;
	}

	ll res = (fact[n] * inv[r]) % mod;
	res = (res * inv[n - r]) % mod;

	return res;
}

void precompute(int n) {

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}

	inv[0] = 1;
	inv[n] = binaryExp(fact[n], mod - 2);
	for (int i = n; i > 0; --i) {
		inv[i - 1] = (i * inv[i]) % mod;
	}
}

int main() {

	int k;
	cin >> k;

	ll c[M + 1];

	for (int i = 1; i <= M; ++i) {
		cin >> c[i];
	}

	precompute(k);

	vector<vector<ll>> dp(M + 1, vector<ll>(k + 1));

	dp[0][0] = 1;

	for (int ch = 1; ch <= M; ++ch) {
		for (int fq = 0; fq <= c[ch]; ++fq) {
			for (int len = 0; len + fq <= k; ++len) {
				dp[ch][len + fq] += (ncr(len + fq, fq) * dp[ch - 1][len]) % mod;
				dp[ch][len + fq] %= mod;
			}
		}
	}

	ll ans = 0;
	for (int len = 1; len <= k; ++len) {
		ans = (ans + dp[M][len]) % mod;
	}

	cout << ans << endl;
}