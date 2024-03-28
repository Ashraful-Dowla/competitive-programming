/*
https://atcoder.jp/contests/abc286/tasks/abc286_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, x, a[55], b[55], dp[55][N];


bool solve(int i, int x) {

	if (i == n) {
		return x == 0;
	}
	if (dp[i][x] != -1) {
		return dp[i][x];
	}

	bool isPossible = false;
	for (int j = 0; j <= b[i]; ++j) {
		if (x - a[i]*j >= 0) {
			isPossible |= solve(i + 1, x - a[i] * j);
		}
	}

	return dp[i][x] = isPossible;
}

int main() {

	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= x; ++j) {
			dp[i][j] = -1;
		}
	}

	cout << (solve(0, x) ? "Yes" : "No") << endl;
}