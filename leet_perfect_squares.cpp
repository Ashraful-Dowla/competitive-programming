/*
https://leetcode.com/problems/perfect-squares/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[10010][110];

int solve(int n, int m) {

	if (n == 0) return 0;
	if (n < 0 || m == 0) return 1e5;
	if (dp[n][m] != -1) return dp[n][m];

	int ans = solve(n - m * m, m) + 1;
	ans = min(ans, solve(n, m - 1));

	return dp[n][m] = ans;
}

int numSquares(int n) {

	int m = sqrt(n) + 1.0;

	for (int i = 0; i <= n + 2; ++i) {
		for (int j = 0; j <= m + 2; ++j) {
			dp[i][j] = -1;
		}
	}
	return solve(n, m);
}

int main() {

	// int n = 12;
	// int n = 13;
	// int n = 7;
	// int n = 43;
	int n = 18;
	cout << numSquares(n);
}