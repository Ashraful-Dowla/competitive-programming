/*
https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
*/
#include <bits/stdc++.h>
using namespace std;

int dp[26];

int longestIdealString(string s, int k) {

	int n = s.size();
	s = "_" + s;

	int ans = 0;
	for (int i = 1; i <= n; ++i) {

		int p = s[i] - 'a';

		int mx = 0;
		for (int j = 0; j <= 25; ++j) {
			if (abs(p - j) <= k) {
				mx = max(mx, dp[j]);
			}
		}

		dp[p] = max(dp[p], mx + 1);
		ans = max(ans, dp[p]);
	}

	return ans;
}

int main() {

	// string s = "acfgbd";
	// int k = 2;

	// string s = "abcd";
	// int k = 3;

	string s = "pvjcci";
	int k = 4;

	cout << longestIdealString(s, k) << endl;
}