/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp = {
	{'(', 1},
	{')', -1}
};

string minRemoveToMakeValid(string s) {

	stack<int> stk;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			continue;
		}
		else if (mp[s[i]] > 0) {
			stk.push(i);
		}
		else if (stk.empty()) {
			s[i] = '-';
		}
		else if (mp[s[stk.top()]] + mp[s[i]] == 0) {
			stk.pop();
		}
		else {
			stk.pop();
			s[i] = '-';
		}
	}

	while (!stk.empty()) {
		s[stk.top()] = '-';
		stk.pop();
	}

	string ans;
	for (char ch : s) {
		if (ch != '-') {
			ans.push_back(ch);
		}
	}

	return ans;
}

int main() {

	string s = "lee(t(c)o)de)";
	// string s = "a)b(c)d";
	// string s = "))((";
	cout << minRemoveToMakeValid(s) << endl;
}