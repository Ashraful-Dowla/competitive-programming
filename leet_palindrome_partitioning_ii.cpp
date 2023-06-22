/*
https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];

bool isPalindrome(string &s, int lo, int hi) {

	while (lo < hi) {
		if (s[lo++] != s[hi--]) return false;
	}

	return true;
}

int solve(string &s, int st, int nd) {

	if (st == s.size()) return 0;
	if (dp[st][nd] != -1) return dp[st][nd];

	int cut = INT_MAX;
	for (int i = st; i <= nd; ++i) {
		if (isPalindrome(s, st, i)) {
			cut = min(cut, solve(s, i + 1, nd) + 1);
		}
	}

	return dp[st][nd] = cut;
}


int minCut(string s) {

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			dp[i][j] = -1;
		}
	}
	return solve(s, 0, s.size() - 1) - 1;
}

int main() {
	// string s = "aab";
	// string s = "abcd";
	string s = "ab";
	cout << minCut(s);
}