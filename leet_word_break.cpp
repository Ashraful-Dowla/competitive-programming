#include <bits/stdc++.h>
using namespace std;

int dp[500];

bool solve(string &s, vector<string>& wordDict, int i) {

	if (i == s.size()) return true;
	if (dp[i] != -1) return dp[i];

	bool isPossible = false;
	for (int idx = 0; idx < wordDict.size(); ++idx) {
		int sz = wordDict[idx].size();
		if (s.substr(i, sz) == wordDict[idx]) {
			isPossible |= solve(s, wordDict, i + sz);
		}
	}

	return dp[i] = isPossible;
}


bool wordBreak(string s, vector<string>& wordDict) {
	for (int i = 0; i < s.size(); ++i) {
		dp[i] = -1;
	}
	return solve(s, wordDict, 0);
}

int main() {

	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	// string s = "applepenapple";
	// vector<string> wordDict = {"apple", "pen"};
	// string s = "catsandog";
	// vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	cout << wordBreak(s, wordDict);
}