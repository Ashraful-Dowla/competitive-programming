/*
https://leetcode.com/problems/longest-common-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(string &s, string &t, int i, int j) {

	if (i == s.size() || j == t.size()) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + solve(s, t, i + 1, j + 1);
	}

	return dp[i][j] = max(solve(s, t, i + 1, j), solve(s, t, i, j + 1));

}

int longestCommonSubsequence(string text1, string text2) {

	for (int i = 0; i < text1.size(); ++i) {
		for (int j = 0; j < text2.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(text1, text2, 0, 0);
}

int main() {

	string text1 = "abcde";
	string text2 = "ace";

	cout << longestCommonSubsequence(text1, text2) << endl;
}