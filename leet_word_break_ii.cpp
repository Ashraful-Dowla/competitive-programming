/*
https://leetcode.com/problems/word-break-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> ans, res;

void solve(string &s, vector<string>& wordDict, int i) {

	if (i == s.size()) {

		string word = res[0];
		for (int i = 1; i < res.size(); ++i) {
			word += (" " + res[i]);
		}
		ans.push_back(word);
		return ;
	}

	for (int idx = 0; idx < wordDict.size(); ++idx) {
		int sz = wordDict[idx].size();
		if (s.substr(i, sz) == wordDict[idx]) {
			res.push_back(wordDict[idx]);
			solve(s, wordDict, i + sz);
			res.pop_back();
		}
	}

}


vector<string> wordBreak(string s, vector<string>& wordDict) {
	solve(s, wordDict, 0);
	return ans;
}

int main() {

	// string s = "catsanddog";
	// vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

	// string s = "pineapplepenapple";
	// vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

	string s = "catsandog";
	vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	vector<string> ans = wordBreak(s, wordDict);

	for (auto x : ans) {
		cout << x << endl;
	}
}