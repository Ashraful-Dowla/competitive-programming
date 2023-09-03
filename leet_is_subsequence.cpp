/*
https://leetcode.com/problems/is-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][10005];

bool solve(string &s, string &t, int i, int j) {

	if (i == s.size()) return true;
	if (j == t.size()) return false;
	if (dp[i][j] != -1) return dp[i][j];

	bool isPossible = false;
	if (s[i] == t[j]) {
		isPossible |= solve(s, t, i + 1, j + 1);
	}
	isPossible |= solve(s, t, i, j + 1);

	return dp[i][j] = isPossible;
}

bool isSubsequence(string s, string t) {

	for (int i = 0; i <= s.size(); ++i) {
		for (int j = 0; j <= t.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(s, t, 0, 0);
}

int main() {

	string s = "abc", t = "ahbgdc";
	// string s = "axc", t = "ahbgdc";

	cout << isSubsequence(s, t) << endl;
}