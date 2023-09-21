/*
https://leetcode.com/problems/longest-palindrome/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp;

int longestPalindrome(string s) {

	int len = s.size();
	for (char ch : s) {
		mp[ch]++;
	}

	int odd = 0;
	for (auto p : mp) {
		if (p.second % 2 == 1)
			odd++;
	}

	return odd > 0 ? len - odd + 1 : len;
}

int main() {

	// string s = "abccccdd";
	// string s = "a";
	string s = "bb";
	cout << longestPalindrome(s) << endl;
}