/*
https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(int n, int k, int p) {

	if (k > n) return 1e6;
	if (k == n) return 0;
	if (dp[k][p] != -1) return dp[k][p];

	int ans = 1e6;
	if (p > 0) {
		ans = min(ans, solve(n, k + p, p) + 1);
	}
	ans = min(ans, solve(n, 2 * k, k) + 2);

	return dp[k][p] = ans;
}

int minSteps(int n) {

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(n, 1, 0);
}

int main() {

	int n = 1;
	cout << minSteps(n) << endl;

}