/*
https://www.spoj.com/problems/BYTESM2/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int a[N][N], dp[N][N];

int solve(int i, int j) {

	if (i == n) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int ans = 0;
	ans = max(ans, solve(i + 1, j) + a[i + 1][j]);
	if (j - 1 >= 0) {
		ans = max(ans, solve(i + 1, j - 1) + a[i + 1][j - 1]);
	}
	if (j + 1 < m) {
		ans = max(ans, solve(i + 1, j + 1) + a[i + 1][j + 1]);
	}

	return dp[i][j] = ans;
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				dp[i][j] = -1;
			}
		}

		for (int i = 0; i < m; ++i) {
			a[n][i] = 0;
		}

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			ans = max(ans, solve(0, i) + a[0][i]);
		}

		cout << ans << endl;
	}
}