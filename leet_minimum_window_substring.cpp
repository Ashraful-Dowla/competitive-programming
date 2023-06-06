/*
https://leetcode.com/problems/minimum-window-substring/
*/
#include <bits/stdc++.h>
using namespace std;


string minWindow(string s, string t) {

	unordered_map<char, int> mp;
	for (char ch : t) {
		mp[ch]++;
	}

	int st = 0, nd = 0, cnt = t.size(), s_sz = s.size(), d = INT_MAX, h = 0;

	while (nd < s_sz) {

		if (mp[s[nd++]]-- > 0) cnt--;

		while (cnt == 0) {
			if (nd - st < d ) {
				d = nd - st;
				h = st;
			}

			if (mp[s[st++]]++ == 0) cnt++;
		}
	}

	return d == INT_MAX ? "" : s.substr(h, d);
}

int main() {
	// string s = "ADOBECODEBANC", t = "ABC";
	// string s = "a", t = "aa";
	string s = "aaaaaaaaaaaabbbbbcdd", t = "abcdd";

	cout << minWindow(s, t);
}