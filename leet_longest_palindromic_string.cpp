/*
https://leetcode.com/problems/longest-palindromic-substring/description/
*/
#include <bits/stdc++.h>
using namespace std;


int mx_len = 1, st = 0;
bool dp[1005][1005];

void chk_length(int i, int j, int len) {
	if (dp[i][j] && mx_len < len) {
		mx_len = len;
		st = i;
	}
}

string longestPalindrome(string s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		dp[i][i] = true;
		chk_length(i, i, 1);

		dp[i][i + 1] = (s[i] == s[i + 1]);
		chk_length(i, i + 1, 2);
	}

	for (int i = 2; i < n; ++i) {
		for (int j = 0; j + i < n; ++j) {
			int _i = j, _j = i + j;
			dp[_i][_j] = (dp[_i + 1][_j - 1] && s[_i] == s[_j]);
			chk_length(_i, _j, _j - _i + 1);
		}
	}

	return s.substr(st, mx_len);
}

int main() {
	string s = "abba";
	cout << longestPalindrome(s) << endl;
}