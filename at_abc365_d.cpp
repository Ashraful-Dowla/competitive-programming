/*
https://atcoder.jp/contests/abc365/tasks/abc365_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, dp[N][20];
string s;

int solve(int i, char c) {

	if (i == n) {
		return 0;
	}
	if (dp[i][c - 'A'] != -1) {
		return dp[i][c - 'A'];
	}

	int ans = 0;
	if (s[i] == 'S') {
		if (c != 'R') {
			ans = max(ans, solve(i + 1, 'R') + 1);
		}
		if (c != 'S') {
			ans = max(ans, solve(i + 1, 'S'));
		}
	}
	else if (s[i] == 'R') {
		if (c != 'P') {
			ans = max(ans, solve(i + 1, 'P') + 1);
		}
		if (c != 'R') {
			ans = max(ans, solve(i + 1, 'R'));
		}
	}
	else {
		if (c != 'S') {
			ans = max(ans, solve(i + 1, 'S') + 1);
		}
		if (c != 'P') {
			ans = max(ans, solve(i + 1, 'P'));
		}
	}

	return dp[i][c - 'A'] = ans;
}

int main() {

	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 20; ++j) {
			dp[i][j] = -1;
		}
	}

	cout << solve(0, s[0]) << endl;
}