/*
https://atcoder.jp/contests/abc344/tasks/abc344_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	bool ok = true;
	for (char ch : s) {
		if (ch == '|') ok = 1 - ok;
		if (ok && ch != '|') cout << ch;
	}
	cout << endl;
}