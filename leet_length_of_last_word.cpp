/*
https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01
*/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {

	s += " ";

	string ans, p;
	for (char ch : s) {
		if (ch == ' ') {
			if (p.size()) {
				ans = p;
				p.clear();
			}
		}
		else {
			p.push_back(ch);
		}
	}

	return ans.size();
}

int main() {

	string s = "Hello World";
	// string s = "   fly me   to   the moon  ";
	// string s = "luffy is still joyboy";

	cout << lengthOfLastWord(s) << endl;
}