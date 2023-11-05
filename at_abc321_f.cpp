/*
https://atcoder.jp/contests/abc321/tasks/abc321_f
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {

	int q, k;
	cin >> q >> k;

	int dp[5005] = {0};

	dp[0] = 1;

	while (q--) {
		char s;
		int x;
		cin >> s >> x;

		if (s == '+') {
			for (int i = k; i >= x; --i) {
				dp[i] = (dp[i] + dp[i - x]) % MOD;
			}
		}
		else {
			for (int i = x; i <= k; ++i) {
				dp[i] = (dp[i] - dp[i - x] + MOD) % MOD;
			}
		}

		cout << dp[k] << endl;
	}
}