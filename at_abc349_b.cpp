/*
https://atcoder.jp/contests/abc349/tasks/abc349_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	unordered_map<char, int> mp;

	for (char ch : s) {
		mp[ch]++;
	}

	for (int i = 1; i <= 100; ++i) {
		set<char> st;
		for (auto p : mp) {
			if (p.second == i) {
				st.insert(p.first);
			}
		}

		if (st.size() == 0 || st.size() == 2) {
			continue;
		}
		else {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
}