/*
https://leetcode.com/problems/valid-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<char, int> mp = {
	{'(', 1},
	{')', -1},
	{'{', 2},
	{'}', -2},
	{'[', 3},
	{']', -3},
};

bool isValid(string s) {

	stack<char> stk;
	for (char ch : s) {

		if (mp[ch] > 0) {
			stk.push(ch);
		}
		else {
			if (stk.empty()) return false;

			if (mp[ch] + mp[stk.top()] == 0) {
				stk.pop();
			}
			else return false;
		}
	}

	return stk.empty();
}

int main() {

	// string s = "()[]{}";
	// string s = "()";
	string s = "(]";
	cout << isValid(s);
}