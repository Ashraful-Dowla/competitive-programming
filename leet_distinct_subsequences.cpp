/*
https://leetcode.com/problems/distinct-subsequences/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(string& s, string& t, int i, int j) {

	if (j < 0) return 1;
	if (i < 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int ct = 0;
	if (s[i] == t[j]) {
		ct += solve(s, t, i - 1, j - 1);
	}
	ct += solve(s, t, i - 1, j);

	return dp[i][j] = ct;
}


int numDistinct(string s, string t) {

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < t.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(s, t, s.size() - 1, t.size() - 1);
}

int main() {
	string s = "rabbbit", t = "rabbit";
	// string s = "babgbag", t = "bag";

	cout << numDistinct(s, t);
}