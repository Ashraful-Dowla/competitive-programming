/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string& s, int k, int l, int r) {

	if (l > r) return 0;

	int fq[26] = {0};

	for (int i = l; i <= r; ++i) {
		fq[s[i] - 'a']++;
	}

	for (int mid = l; mid <= r; ++mid) {
		if (fq[s[mid] - 'a'] < k) {
			return max(solve(s, k, l, mid - 1), solve(s, k, mid + 1, r));
		}
	}

	return r - l + 1;
}

int longestSubstring(string s, int k) {
	return solve(s, k, 0, s.size() - 1);
}

int main() {

	// string s = "ababcabaaadc";
	// int k = 2;

	// string s = "ababbc";
	// int k = 2;

	// string s = "aaabb";
	// int k = 3;

	// string s = "ababacb";
	// int k = 3;

	string s = "bbaaacddcaabdbd";
	int k = 3;

	cout << longestSubstring(s, k);
}