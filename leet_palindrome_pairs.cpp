/*
https://leetcode.com/problems/palindrome-pairs/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
unordered_map<string, int> mp;
bool taken[5005][5005];

bool isPalidrome(string s) {
	int lo = 0, hi = s.size() - 1;

	while (lo < hi) {
		if (s[lo] != s[hi]) return false;
		lo++, hi--;
	}

	return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {

	for (int i = 0; i < words.size(); ++i) {
		string s = words[i];
		reverse(s.begin(), s.end());
		mp[s] = i;
	}

	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j <= words[i].size(); ++j) {
			string pf = words[i].substr(0, j);
			string sf = words[i].substr(j);

			auto it = mp.find(sf);

			if (it != mp.end() && it->second != i && isPalidrome(pf)) {

				if (!taken[it->second][i]) {
					ans.push_back({it->second, i});
					taken[it->second][i] = true;
				}
			}

			it = mp.find(pf);

			if (it != mp.end() && it->second != i && isPalidrome(sf)) {

				if (!taken[i][it->second]) {
					ans.push_back({i, it->second});
					taken[i][it->second] = true;
				}
			}
		}
	}

	return ans;
}

int main() {

	// vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
	// vector<string> words = {"bat", "tab", "cat"};
	// vector<string> words = {"a", "", "c"};
	// vector<string> words = {"a", ""};
	vector<string> words = {"a", "b", "c", "ab", "ac", "aa"};

	auto res = palindromePairs(words);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << endl;
	}
}