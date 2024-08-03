/*
https://atcoder.jp/contests/abc275/tasks/abc275_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> dp;

ll solve(ll n) {

	if (n == 0) return 1;
	if (dp.find(n) != dp.end()) {
		return dp[n];
	}

	return dp[n] = solve(n / 2) + solve(n / 3);
}

int main() {

	ll n;
	cin >> n;

	cout << solve(n) << endl;
}