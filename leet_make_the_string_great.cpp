/*
https://leetcode.com/problems/make-the-string-great/submissions/1223712998/?envType=daily-question&envId=2024-04-05
*/
#include <bits/stdc++.h>
using namespace std;

bool check(char c1, char c2) {
	return abs(c1 - c2) == 32;
}

string makeGood(string s) {

	stack<char> stk;
	for (char ch : s) {
		if (!stk.empty() && check(stk.top(), ch)) {
			stk.pop();
		}
		else {
			stk.push(ch);
		}
	}

	string res;
	while (!stk.empty()) {
		res.push_back(stk.top());
		stk.pop();
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {

	string s = "leEeetcode";
	// string s = "abBAcC";

	cout << makeGood(s) << endl;
}