/*
https://leetcode.com/problems/reverse-words-in-a-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

	int n = s.size();

	string ans;
	for (int i = 0; i < n; ++i) {
		string res;
		if (s[i] != ' ') {
			res.push_back(s[i++]);

			while (i < n && s[i] != ' ') {
				res.push_back(s[i++]);
			}

			if (ans.size()) {
				ans = res + " " + ans;
			}
			else ans = res;
		}
	}


	return ans;
}

int main() {

	string s = "  hello world  ";
	// string s = "the sky is blue";
	// string s = "a good   example";
	// string s = "    a    cb";

	cout << reverseWords(s);
}