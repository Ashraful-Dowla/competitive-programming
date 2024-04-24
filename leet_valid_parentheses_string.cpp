/*
https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07
*/
#include <bits/stdc++.h>
using namespace std;

int dp[200][200];

bool solve(string &s, int i, int res) {

	if (i >= s.size()) {
		return res == 0;
	}
	if (res < 0) {
		return false;
	}
	if (dp[i][res] != -1) {
		return dp[i][res];
	}

	bool isPossible = false;
	if (s[i] == '(') {
		isPossible |= solve(s, i + 1, res + 1);
	}
	else if (s[i] == ')') {
		isPossible |= solve(s, i + 1, res - 1);
	}
	else {
		isPossible |= solve(s, i + 1, res);
		isPossible |= solve(s, i + 1, res + 1);
		isPossible |= solve(s, i + 1, res - 1);
	}

	return dp[i][res] = isPossible;
}

bool checkValidString(string s) {

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < 200; ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(s, 0, 0);
}

int main() {

	// string s = "(*)";
	// string s = "(*))";
	string s = "()";
	cout << checkValidString(s) << endl;
}