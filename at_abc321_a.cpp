/*
https://atcoder.jp/contests/abc321/tasks/abc321_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	bool ok = true;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] < s[i - 1]) continue;
		ok = false;
		break;
	}

	cout << (ok ? "Yes" : "No") << endl;
}