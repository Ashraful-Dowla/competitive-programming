/*
https://leetcode.com/problems/scramble-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool>mp;

bool solve(string s1, string s2) {

	if (s1.size() == 1) return s1 == s2;
	if (s1 == s2) return true;

	string key = s1 + s2;
	if (mp.find(key) != mp.end()) return mp[key];

	int n = s1.size();
	bool isPossible = false;
	for (int i = 1; i < n; ++i) {

		isPossible |= solve(s1.substr(0, i), s2.substr(0, i))
		              && solve(s1.substr(i), s2.substr(i));

		isPossible |= solve(s1.substr(0, i), s2.substr(n - i))
		              && solve(s1.substr(i), s2.substr(0, n - i));
	}

	return mp[key] = isPossible;
}

bool isScramble(string s1, string s2) {
	return solve(s1, s2);
}


int main() {
	string s1 = "aaccd", s2 = "acaad";

	cout << isScramble(s1, s2);
}