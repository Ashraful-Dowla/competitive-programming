/*
https://atcoder.jp/contests/abc323/tasks/abc323_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	s = '_' + s;

	bool ok = true;
	for (int i = 2; i <= 16; i += 2) {
		if (s[i] == '0') continue;
		ok = false;
		break;
	}

	cout << (ok ? "Yes" : "No") << endl;
}