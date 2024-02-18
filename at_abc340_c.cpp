/*
https://atcoder.jp/contests/abc340/tasks/abc340_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<ll, ll> dp;

ll solve(ll n) {

	if (n < 2) return 0;
	if (dp.find(n) != dp.end()) {
		return dp[n];
	}

	ll res = 0;

	ll lo = n / 2;
	if (lo > 1) {
		res += lo + solve(lo);
	}

	ll hi = (n + 1) / 2;
	if (hi > 1) {
		res += hi + solve(hi);
	}

	return dp[n] = res;
}

int main() {

	ll n;
	cin >> n;

	ll ans = solve(n) + (n > 1 ? n : 0);

	cout << ans << endl;
}