/*
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/submissions/1222838683/?envType=daily-question&envId=2024-04-04
*/
#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {

	int l = 0, ans = 0;
	for (char ch : s) {

		if (ch == '(') {
			l++;
		}
		else if (ch == ')') {
			l--;
		}

		ans = max(ans, l);
	}

	return ans;
}

int main() {

	// string s = "(1+(2*3)+((8)/4))+1";
	string s = "(1)+((2))+(((3)))";

	cout << maxDepth(s) << endl;
}