/*
https://leetcode.com/problems/basic-calculator/
*/
#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {

	s = '(' + s + ')';
	int n = s.size();

	stack<string> stk;

	for (int i = 0; i < n; ++i) {

		if (s[i] == ' ') continue;
		if (s[i] == ')') {

			vector<int> vec;
			while (!stk.empty() && stk.top() != "(") {
				string st = stk.top();
				stk.pop();

				if (st == "-") {
					int sz = vec.size() - 1;
					vec[sz] *= -1;
				}
				else if (st != "+") {
					vec.push_back(stoi(st));
				}
			}

			stk.pop();
			int res = accumulate(vec.begin(), vec.end(), 0);
			stk.push(to_string(res));
		}
		else {

			string t;
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				t.push_back(s[i++]);
			}

			if (t.size()) {
				stk.push(t);
				--i;
			}
			else stk.push(string(1, s[i]));
		}
	}

	return stoi(stk.top());
}

int main() {

	// string s = "1 + 1";
	// string s = " 2-1 + 2 ";
	// string s = "(1+(4+5+2)-3)+(6+8)";
	// string s = "-2+1";
	string s = "0-2+13";

	cout << calculate(s);
}