/*
https://leetcode.com/problems/integer-break/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100];

int solve(int n) {

	if (n == 0) return 1;
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];

	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, solve(n - i) * 1LL * i);
	}

	return dp[n] = ans;
}

int integerBreak(int n) {

	for (int i = 0; i <= n; ++i) {
		dp[i] = -1;
	}

	ll ans = 1;
	for (int i = 1; i < n; ++i) {
		ans = max(ans, solve(n - i) * 1LL * i);
	}

	return ans;
}

int main() {

	int n = 5;
	for (int i = 2; i <= 58; ++i) {
		cout << i << " " << integerBreak(i) << endl;
	}
}