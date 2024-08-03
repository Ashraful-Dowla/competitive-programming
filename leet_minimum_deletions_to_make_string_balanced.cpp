/*
https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30
*/
#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {

	int ans = 0;

	stack<char> stk;
	for (char ch : s) {
		if (stk.empty() || stk.top() == ch) {
			stk.push(ch);
		}
		else if (ch == 'a') {
			stk.pop();
			ans++;
		}
		else {
			stk.push(ch);
		}
	}

	return ans;
}

int main() {

	string s = "aababbab";
	// string s = "bbaaaaabb";
	// string s = "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb";
	cout << minimumDeletions(s) << endl;
}