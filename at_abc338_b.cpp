/*
https://atcoder.jp/contests/abc338/tasks/abc338_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	map<char, int> mp;
	int mx = 0;

	for (char ch : s) {
		mp[ch]++;
		mx = max(mx, mp[ch]);
	}

	set<char>st;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (mp[ch] == mx) {
			st.insert(ch);
		}
	}

	cout << *st.begin() << endl;
}