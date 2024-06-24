/*
https://atcoder.jp/contests/abc359/tasks/abc359_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

int n, k;
ll dp[1005][1200];
string s;

bool isPalindrome(int mask) {

	int lo = 0, hi = k - 1;
	while (lo < hi) {
		int p1 = (mask & (1 << lo)) > 0;
		int p2 = (mask & (1 << hi)) > 0;
		if (p1 != p2) return false;
		lo++, hi--;
	}

	return true;
}

ll getmask(int mask, int i, int c) {
	if (i < k) return mask + c * (1 << i);
	return (mask >> 1) + c * (1 << (k - 1));
}

ll solve(int i, int mask) {

	if (i >= k && isPalindrome(mask)) {
		return 0;
	}
	if (i >= n) {
		return 1;
	}
	if (dp[i][mask] != -1) {
		return dp[i][mask];
	}

	ll ans = 0;
	if (s[i] == '?') {
		ans += solve(i + 1, getmask(mask, i, 0)) + solve(i + 1, getmask(mask, i, 1));
		ans %= mod;
	}
	else {
		ans += solve(i + 1, getmask(mask, i, s[i] == 'A'));
		ans %= mod;
	}


	return dp[i][mask] = ans;
}

int main() {

	cin >> n >> k;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= (1 << k); ++j) {
			dp[i][j] = -1;
		}
	}

	cout << solve(0, 0) << endl;
}