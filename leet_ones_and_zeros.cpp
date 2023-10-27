/*
https://leetcode.com/problems/ones-and-zeroes/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[605][105][105];

int solve(vector<string>& strs, int m, int n, int idx, int zeros, int ones) {

	if (idx == strs.size()) {
		return 0;
	}
	if (dp[idx][zeros][ones] != -1) return dp[idx][zeros][ones];

	int z = 0, o = 0;
	for (char ch : strs[idx]) {
		if (ch == '0') z++;
		else o++;
	}

	int cnt = 0;
	if (zeros + z <= m && ones + o <= n) {
		cnt = max(cnt, solve(strs, m, n, idx + 1, zeros + z, ones + o) + 1);
	}

	cnt = max(cnt, solve(strs, m, n, idx + 1, zeros, ones));

	return dp[idx][zeros][ones] = cnt;
}

int findMaxForm(vector<string>& strs, int m, int n) {

	for (int i = 0; i <= strs.size(); ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= n; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	return solve(strs, m, n, 0, 0, 0);
}

int main() {

	// vector<string> strs = {"10", "0001", "111001", "1", "0"};
	// int m = 5, n = 3;

	vector<string> strs = {"10", "0", "1"};
	int m = 1, n = 1;

	cout << findMaxForm(strs, m, n);
}