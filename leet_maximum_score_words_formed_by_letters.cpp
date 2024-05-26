/*
https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/?envType=daily-question&envId=2024-05-24
*/
#include <bits/stdc++.h>
using namespace std;

map<string, int>mp;
int cnt[25][26], let[26], ans, res;

bool check(int i) {
	for (int j = 0; j < 26; ++j) {
		if (let[j] < cnt[i][j]) {
			return false;
		}
	}
	return true;
}

void solve(vector<string>& words, int i) {

	if (i >= words.size()) {
		ans = max(ans, res);
		return ;
	}

	if (check(i)) {

		for (int j = 0; j < 26; ++j) {
			let[j] -= cnt[i][j];
		}

		res += mp[words[i]];
		solve(words, i + 1);
		res -= mp[words[i]];

		for (int j = 0; j < 26; ++j) {
			let[j] += cnt[i][j];
		}
	}

	solve(words, i + 1);
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

	for (string s : words) {
		if (mp.find(s) != mp.end()) {
			continue;
		}
		for (char ch : s) {
			mp[s] += score[ch - 'a'];
		}
	}

	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < words[i].size(); ++j) {
			cnt[i][words[i][j] - 'a']++;
		}
	}

	for (char ch : letters) {
		let[ch - 'a']++;
	}

	solve(words, 0);

	return ans;
}

int main() {

	vector<string> words = {"dog", "cat", "dad", "good"};
	vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
	vector<int> score = {
		1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};


	cout << maxScoreWords(words, letters, score) << endl;
}