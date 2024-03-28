/*
https://www.spoj.com/problems/ASSIGN/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;

int a[25][25];
ll dp[25][N];

ll solve(int n, int i, int mask) {

	if (i == n) {
		return 1;
	}
	if (dp[i][mask] != -1) {
		return dp[i][mask];
	}

	ll ans = 0;
	for (int j = 0; j < n; ++j) {
		if (a[i][j] == 1 && !(mask & (1 << j))) {
			ans += solve(n, i + 1, mask | 1 << j);
		}
	}

	return dp[i][mask] = ans;
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= (1 << n); ++j) {
				dp[i][j] = -1;
			}
		}

		cout << solve(n, 0, 0) << endl;
	}
}