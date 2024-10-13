/*
https://atcoder.jp/contests/abc375/tasks/abc375_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105, INF = 1e5, M = 1505;
int a[N], b[N], n, t;
int dp[N][M][M];


int solve(int i, int x, int y) {

	if (x < 0 || y < 0 || x > t || y > t) return INF;
	if (i >= n) {
		int z = t - x - y;
		if (x == y && y == z) {
			return 0;
		}
		return INF;
	}
	if (dp[i][x][y] != -1) {
		return dp[i][x][y];
	}

	int ans = solve(i + 1, x, y);
	if (a[i] == 1) {
		ans = min(ans, solve(i + 1, x - b[i], y + b[i]) + 1);
		ans = min(ans, solve(i + 1, x - b[i], y) + 1);
	}
	else if (a[i] == 2) {
		ans = min(ans, solve(i + 1, x + b[i], y - b[i]) + 1);
		ans = min(ans, solve(i + 1, x, y - b[i]) + 1);
	}
	else {
		ans = min(ans, solve(i + 1, x, y + b[i]) + 1);
		ans = min(ans, solve(i + 1, x + b[i], y) + 1);
	}

	return dp[i][x][y] = ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	int tx = 0, ty = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			tx += b[i];
		}
		else if (a[i] == 2) {
			ty += b[i];
		}
		t += b[i];
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= t; ++j) {
			for (int k = 0; k <= t; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	int ans = solve(0, tx, ty);
	cout << (ans == INF ? -1 : ans) << endl;
}