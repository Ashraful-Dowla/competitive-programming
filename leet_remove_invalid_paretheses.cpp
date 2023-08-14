/*
https://leetcode.com/problems/remove-invalid-parentheses/description/
*/
#include <bits/stdc++.h>
using namespace std;

string t;
set<string> st;
int sz = -1;

void solve(string &s, int idx, int left, int right) {

	if (idx == s.size()) {
		if (left == right) {
			int t_sz = t.size();
			if (t_sz > sz) {
				st.clear();
				st.insert(t);
				sz = t_sz;
			}
			else if (t_sz == sz) {
				st.insert(t);
			}
		}

		return ;
	}


	if (s[idx] == '(') {
		t.push_back(s[idx]);
		solve(s, idx + 1, left + 1, right);
		t.pop_back();

		solve(s, idx + 1, left, right);
	}
	else if (s[idx] == ')') {

		if (left > right) {
			t.push_back(s[idx]);
			solve(s, idx + 1, left, right + 1);
			t.pop_back();
		}

		solve(s, idx + 1, left, right);
	}
	else {
		t.push_back(s[idx]);
		solve(s, idx + 1, left, right);
		t.pop_back();
	}

}

vector<string> removeInvalidParentheses(string s) {

	solve(s, 0, 0, 0);

	vector<string> ans;

	for (string v : st) {
		ans.push_back(v);
	}

	return ans;
}

int main() {

	// string s = "()())()";
	// string s = "(a)())()";
	// string s = "(a)())()()))))())))()()";
	string s = "n";
	// string s = "h)))uq))v)))))))()";
	// string s = "))))))))))))))))))))aaaaa";

	auto vec = removeInvalidParentheses(s);

	for (string v : vec) {
		cout << v << endl;
	}
}