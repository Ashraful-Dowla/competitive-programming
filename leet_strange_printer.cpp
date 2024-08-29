/*
https://leetcode.com/problems/strange-printer/submissions/1363159972/?envType=daily-question&envId=2024-08-21
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int solve(string&s, int l, int r) {

	if (l > r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int ans = 1 + solve(s, l + 1, r);
	for (int k = l + 1; k <= r; ++k) {
		if (s[l] == s[k]) {
			int res = solve(s, l, k - 1) + solve(s, k + 1, r);
			ans = min(ans, res);
		}
	}

	return dp[l][r] = ans;
}


int strangePrinter(string s) {

	int i = 0;
	string unq_char;

	while (i < s.size()) {
		char ch = s[i];
		unq_char.push_back(ch);
		while (i < s.size() && s[i] == ch) {
			++i;
		}
	}

	s = unq_char;

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(s, 0, s.size() - 1);
}

int main() {

	// string s = "aba";
	// string s = "aaabbb";
	// string s = "aaaacccaaasss";
	string s = "tbgtgb";

	cout << strangePrinter(s) << endl;
}