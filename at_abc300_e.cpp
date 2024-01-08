/*
https://atcoder.jp/contests/abc300/tasks/abc300_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll N, inv;
map<ll, ll>dp;

ll binaryExp(ll a, ll b) {

	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}

	return res;
}

ll solve(ll n) {

	if (n == N) return 1;
	if (n > N) return 0;
	if (dp.find(n) != dp.end()) {
		return dp[n];
	}

	ll ans = 0;
	for (int i = 2; i <= 6; ++i) {
		ans += solve(i * n);
	}

	return dp[n] = (ans * inv) % MOD;
}

int main() {

	cin >> N;

	inv = binaryExp(5, MOD - 2);

	cout << solve(1) << endl;
}