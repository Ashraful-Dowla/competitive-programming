/*
https://atcoder.jp/contests/abc315/tasks/abc315_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef double ld;

const int N = 1e4 + 10;
const int K = 60;
const ld INF = 1e10;

ld dp[N][K], X[N], Y[N];

ld distance(int i, int j) {

	ld dis = (X[i] - X[j]) * (X[i] - X[j]);
	dis += (Y[i] - Y[j]) * (Y[i] - Y[j]);

	return sqrt(dis);
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> X[i] >> Y[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < K; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[1][0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < K; ++j) {
			for (int l = i + 1; l <= n && j + l - i - 1 < K; ++l) {
				int jj = j + l - i - 1;
				dp[l][jj] = min(dp[l][jj], dp[i][j] + distance(i, l));
			}
		}
	}

	ld ans = INF;
	for (int j = 0; j < K; ++j) {
		ans = min(ans, dp[n][j] + (j == 0 ? 0 : (1LL << j - 1)));
	}

	cout << fixed << setprecision(10) << ans << endl;
}