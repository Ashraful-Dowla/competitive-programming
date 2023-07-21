/*
https://leetcode.com/problems/basic-calculator-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isDivideOrMultipy(string s) {
	return s == "*" || s == "/";
}

int calculate(string s) {

	int n = s.size();
	stack<string> stk;

	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ') continue;

		string num;
		while (i < n && isDigit(s[i])) {
			num.push_back(s[i++]);
		}

		if (num.size()) {
			if (!stk.empty() && isDivideOrMultipy(stk.top())) {
				string sign = stk.top();
				stk.pop();

				long res = stoi(stk.top());
				stk.pop();

				if (sign == "*") res *= stoi(num);
				else res /= stoi(num);

				stk.push(to_string(res));
			}
			else stk.push(num);
		}

		if (i < n && isOperator(s[i])) {
			stk.push(string(1, s[i]));
		}
	}

	vector<int> ans;

	while (!stk.empty()) {
		string s = stk.top();
		stk.pop();

		if (s == "-") {
			int sz = ans.size() - 1;
			ans[sz] *= -1;
		}
		else if (s != "+") {
			ans.push_back(stoi(s));
		}
	}

	return accumulate(ans.begin(), ans.end(), 0);
}

int main() {

	// string s = "3+2*2";
	string s = "1 + 2 * 5 / 3 + 6 / 4 * 2";
	// string s = " 3/2 ";
	// string s = " 3+5 / 2 ";
	cout << calculate(s);
}