/*
https://atcoder.jp/contests/abc323/tasks/abc323_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 998244353;

ll binaryExp(ll a, ll b) {

	ll ans = 1;

	while (b) {
		if (b & 1) {
			ans = (ans * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}

	return ans;
}

int main() {

	int n;
	ll x;
	cin >> n >> x;

	vector<int> t(n);

	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	vector<ll> prob_start(x + 1), prob_end(x + 1);

	ll inv = binaryExp(n, MOD - 2);

	prob_start[0] = inv;

	for (int j = 0; j < n; ++j) {
		prob_end[t[j]] = (prob_end[t[j]] + inv) % MOD;
	}

	for (int time = 1; time <= x; ++time) {

		prob_start[time] = (prob_start[time] + (prob_end[time] * inv) % MOD) % MOD;

		for (int i = 0; i < n; ++i) {
			if (time + t[i] <= x) {
				prob_end[time + t[i]] = (prob_end[time + t[i]] +
				                         (prob_end[time] * inv) % MOD) % MOD;
			}
		}
	}

	ll ans = 0;
	for (ll time = x; time > max(x - t[0], -1LL); --time) {
		ans = (ans + prob_start[time]) % MOD;
	}

	cout << ans << endl;
}