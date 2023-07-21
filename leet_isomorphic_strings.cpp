/*
https://leetcode.com/problems/isomorphic-strings/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp_s, mp_t;

bool isIsomorphic(string s, string t) {

	for (int i = 0; i < s.size(); ++i) {
		if (mp_s[s[i]] == 0 && mp_t[t[i]] == 0) {
			mp_s[s[i]] = t[i];
			mp_t[t[i]] = s[i];
		}
		else if ((char)mp_s[s[i]] == t[i]) continue;
		else return false;
	}

	return true;
}

int main() {
	string s = "egg", t = "add";
	// string s = "foo", t = "bar";
	// string s = "paper", t = "title";
	// string s = "badc", t = "baba";

	cout << isIsomorphic(s, t);
}