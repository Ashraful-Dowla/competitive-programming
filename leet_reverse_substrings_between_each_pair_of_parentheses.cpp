/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
*/
#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) {

	stack<char> stk;

	for (char ch : s) {

		if (ch != ')') {
			stk.push(ch);
		}
		else {
			string p;
			while (!stk.empty() && stk.top() != '(') {
				p.push_back(stk.top());
				stk.pop();
			}

			stk.pop();

			for (char ch : p) {
				stk.push(ch);
			}
		}
	}

	string ans;
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {

	// string s = "(ed(et(oc))el)";
	string s = "(u(love)i)";
	cout << reverseParentheses(s) << endl;
}