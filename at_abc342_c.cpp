/*
https://atcoder.jp/contests/abc342/tasks/abc342_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int q;
	cin >> q;

	unordered_map<char, char>mp;

	for (char ch = 'a'; ch <= 'z'; ++ch) {
		mp[ch] = ch;
	}

	while (q--) {
		char c, d;
		cin >> c >> d;
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (mp[ch] == c) {
				mp[ch] = d;
			}
		}
	}

	for (char ch : s) {
		cout << mp[ch];
	}
	cout << endl;

}