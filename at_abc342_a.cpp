/*
https://atcoder.jp/contests/abc342/tasks/abc342_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	set<char>st;
	unordered_map<char, int> mp, idx;

	for (int i = 0; i < s.size(); ++i) {
		st.insert(s[i]);
		mp[s[i]]++;
		idx[s[i]] = i + 1;
	}

	for (char ch : st) {
		if (mp[ch] == 1) {
			cout << idx[ch] << endl;
			return 0;
		}
	}
}