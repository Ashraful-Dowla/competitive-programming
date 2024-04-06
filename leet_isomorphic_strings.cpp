/*
https://leetcode.com/problems/isomorphic-strings/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {

	unordered_map<char, char> mp_s, mp_t;

	for (int i = 0; i < s.size(); ++i) {
		if (mp_s.find(s[i]) == mp_s.end() && mp_t.find(t[i]) == mp_t.end()) {
			mp_s[s[i]] = t[i];
			mp_t[t[i]] = s[i];
		}
		else if (mp_s[s[i]] == t[i]) {
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}

int main() {
	// string s = "egg", t = "add";
	// string s = "foo", t = "bar";
	// string s = "paper", t = "title";
	string s = "badc", t = "baba";

	cout << isIsomorphic(s, t);
}