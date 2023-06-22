/*
https://leetcode.com/problems/palindrome-partitioning/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<string>temp;

bool isPalindrome(string &s, int lo, int hi) {

	while (lo < hi) {
		if (s[lo++] != s[hi--]) return false;
	}

	return true;
}

void dfs(string &s, int st) {

	if (st == s.size()) {
		ans.push_back(temp);
		return ;
	}

	for (int nd = st; nd < s.size(); ++nd) {
		if (isPalindrome(s, st, nd)) {

			temp.push_back(s.substr(st, nd - st + 1));
			dfs(s, nd + 1);
			temp.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	dfs(s, 0);
	return ans;
}

int main() {

	string s = "aaab";
	auto res = partition(s);

	for (auto v : res) {
		for (string c : v) {
			cout << c << " ";
		}
		cout << endl;
	}
}