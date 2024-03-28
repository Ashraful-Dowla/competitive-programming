/*
https://www.spoj.com/problems/ANARC09A/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

	stack<char>stk;

	int ans = 0;
	for (char ch : s) {
		if (ch == '{') {
			stk.push(ch);
		}
		else {
			if (stk.empty()) {
				stk.push('{');
				ans++;
			}
			else {
				char top = stk.top();
				stk.pop();
				if (top == '}') {
					ans++;
				}
			}
		}
	}

	return ans + stk.size() / 2;
}

int main() {

	int k = 1;
	while (true) {
		string s;
		cin >> s;

		if (s[0] == '-') {
			break;
		}

		cout << k++ << ". " << solve(s) << endl;
	}
}