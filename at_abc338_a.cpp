/*
https://atcoder.jp/contests/abc338/tasks/abc338_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	if (s[0] >= 'A' && s[0] <= 'Z') {

		for (int i = 1; i < s.size(); ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				continue;
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}

		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}