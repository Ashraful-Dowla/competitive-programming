/*
https://atcoder.jp/contests/abc280/tasks/abc280_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	string t;
	cin >> t;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != t[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << s.size() + 1 << endl;
}