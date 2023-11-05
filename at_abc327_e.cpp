/*
https://atcoder.jp/contests/abc327/tasks/abc327_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<double> p(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	double dp[n + 1][n + 1];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = INT_MIN;
		}
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = max(dp[i - 1][1], p[i]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j < i; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] * 0.9 + p[i]);
		}
		dp[i][i] = dp[i - 1][i - 1] * 0.9 + p[i];
	}

	vector<double>pw(n + 1);
	double c = 1;

	for (int i = 1; i <= n; ++i) {
		pw[i] = pw[i - 1] + c;
		c *= 0.9;
	}

	double ans = INT_MIN;
	for (int k = 1; k <= n; ++k) {
		double num = dp[n][k] / pw[k];
		double sq = 1200 / sqrt(k * 1.0);

		ans = max(ans, num - sq);
	}

	cout << fixed << setprecision(15) << ans << endl;
}