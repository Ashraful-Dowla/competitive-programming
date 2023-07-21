/*
https://leetcode.com/problems/shortest-palindrome/description/
*/
#include <bits/stdc++.h>
using namespace std;

int lps[100005];

int kmpPreprocess(string s) {

	int n = s.size();
	int i = 0, j = 1;

	while (j < n) {

		while (i > 0 && s[i] != s[j]) {
			i = lps[i - 1];
		}

		if (s[i] == s[j]) {
			i++;
		}

		lps[j] = i;
		++j;
	}

	return lps[n - 1];
}

string shortestPalindrome(string s) {

	int n = s.size();
	string r = s;
	reverse(r.begin(), r.end());

	int d = kmpPreprocess(s + "#" + r);

	string t;
	for (int i = 0; i < n - d; ++i) {
		t.push_back(r[i]);
	}

	return t + s;

}

int main() {

	// string s = "aacecaaa";
	// string s = "abcd";
	// string s = "abb";
	// string s = "aaaa";
	// string s = "aabba";
	// string s = "abab";


	cout << shortestPalindrome(s);
}