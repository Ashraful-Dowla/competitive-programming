/*
https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& words) {

	int n = words.size();

	vector<vector<int>> cnt(n, vector<int>(30, 0));

	for (int i = 0; i < n; ++i) {
		for (char ch : words[i]) {
			cnt[i][ch - 'a']++;
		}
	}

	vector<string> ans;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		int mn = 1e9;
		for (int i = 0; i < n; ++i) {
			mn = min(mn, cnt[i][ch - 'a']);
		}

		for (int i = 0; i < mn; ++i) {
			ans.push_back(string(1, ch));
		}
	}

	return ans;
}

int main() {

	vector<string> words = {"bella", "label", "roller"};
	// vector<string> words = {"cool", "lock", "cook"};

	auto res = commonChars(words);

	for (string s : res) {
		cout << s << endl;
	}
}