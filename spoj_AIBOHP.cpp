/*
https://www.spoj.com/problems/AIBOHP/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 6200;
int dp[N][N];

int solve(string &s, int i, int j) {

	if (i > j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int ans = 1e6;
	if (s[i] == s[j]) {
		ans = min(ans, solve(s, i + 1, j - 1));
	}
	else {
		ans = min(ans, solve(s, i + 1, j) + 1);
		ans = min(ans, solve(s, i, j - 1) + 1);
	}

	return dp[i][j] = ans;
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		for (int i = 0; i <= s.size(); ++i) {
			for (int j = 0; j <= s.size(); ++j) {
				dp[i][j] = -1;
			}
		}

		cout << solve(s, 0, s.size() - 1) << endl;
	}
}