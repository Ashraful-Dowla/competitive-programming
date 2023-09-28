/*
https://leetcode.com/problems/reconstruct-original-digits-from-english/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp = {
	{'z', 0},
	{'w', 2},
	{'u', 4},
	{'x', 6},
	{'g', 8},
	{'o', 1},
	{'h', 3},
	{'f', 5},
	{'s', 7},
	{'i', 9}
};

string originalDigits(string s) {

	unordered_map<char, int> cnt;
	int num[10] = {0};

	for (int i = 0; i < s.size(); ++i) {
		cnt[s[i]]++;
	}

	string unq = "zwuxg";

	for (char ch : unq) {
		num[mp[ch]] = cnt[ch];
	}

	char ch = 'o';
	num[mp[ch]] = cnt[ch] - num[0] - num[2] - num[4];

	ch = 'h';
	num[mp[ch]] = cnt[ch] - num[8];

	ch = 'f';
	num[mp[ch]] = cnt[ch] - num[4];

	ch = 's';
	num[mp[ch]] = cnt[ch] - num[6];

	ch = 'i';
	num[mp[ch]] = cnt[ch] - num[5] - num[6] - num[8];

	string ans;
	for (int i = 0; i <= 9; ++i) {
		for (int j = 0; j < num[i]; ++j) {
			char ch = '0' + i;
			ans.push_back(ch);
		}
	}

	return ans;
}

int main() {

	// string s = "owoztneoer";
	// string s = "fviefuro";
	string s = "zerozeroone";
	cout << originalDigits(s) << endl;
}