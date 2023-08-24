/*
https://leetcode.com/problems/remove-duplicate-letters/description/
*/
#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {

	vector<int> fq(30, 0);
	vector<bool> visited(30, false);

	for (char ch : s) {
		fq[ch - 'a']++;
	}

	stack<char> stk;
	for (char ch : s) {

		if (visited[ch - 'a']) {
			fq[ch - 'a']--;
		}
		else {

			while (!stk.empty() && stk.top() > ch && fq[stk.top() - 'a'] > 0) {
				visited[stk.top() - 'a'] = false;
				stk.pop();
			}

			stk.push(ch);
			visited[ch - 'a'] = true;
			fq[ch - 'a']--;
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

	string s = "bcabc";
	// string s = "cbacdcbc";

	cout << removeDuplicateLetters(s);
}