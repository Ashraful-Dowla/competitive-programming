/*
https://leetcode.com/problems/integer-replacement/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, unordered_map<ll, ll>& dp) {

	if (n <= 0) return 1e5;
	if (n == 1) return 0;
	if (dp.find(n) != dp.end()) return dp[n];

	ll ans = 1e5;
	if (n % 2 == 0) {
		ans = min(ans, solve(n / 2, dp) + 1LL);
	}
	else {
		ans = min(ans, solve(n + 1, dp) + 1LL);
		ans = min(ans, solve(n - 1, dp) + 1LL);
	}

	return dp[n] = ans;
}


int integerReplacement(int n) {
	unordered_map<ll, ll> dp;
	return solve(n, dp);
}

int main() {

	int n = 2147483647;
	cout << integerReplacement(n) << endl;
}