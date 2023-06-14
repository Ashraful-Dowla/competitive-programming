/*
https://leetcode.com/problems/decode-ways/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105], n;

int solve(string s, int i) {

	if (i == n) return 1;
	if (dp[i] != -1) return dp[i];

	int cnt = 0;
	if (s[i] == '1') {
		if (i + 1 < n) cnt += solve(s, i + 2);
		cnt += solve(s, i + 1);
	}
	else if (s[i] == '2') {
		if (i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '6') {
			cnt += solve(s, i + 2);
		}
		cnt += solve(s, i + 1);
	}
	else if (s[i] != '0') {
		cnt += solve(s, i + 1);
	}

	return dp[i] = cnt;
}

int numDecodings(string s) {
	n = s.size();
	memset(dp, -1, sizeof(dp));
	return solve(s, 0);
}

int main() {
	// string s = "11106";
	// string s = "226";
	// string s = "06";
	string s = "11";
	cout << numDecodings(s);
}