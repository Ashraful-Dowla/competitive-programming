/*
https://atcoder.jp/contests/abc349/tasks/abc349_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	string t;
	cin >> t;

	int k = 0;
	for (int i = 0; i < s.size() && k < t.size(); ++i) {
		if (s[i] == tolower(t[k])) {
			k++;
		}
	}

	if (k == t.size()) {
		cout << "Yes" << endl;
	}
	else if (k + 1 == t.size() && t[2] == 'X') {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}