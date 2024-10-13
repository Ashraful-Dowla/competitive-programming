/*
https://atcoder.jp/contests/abc372/tasks/abc372_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	for (char ch : s) {
		if (ch != '.') {
			cout << ch;
		}
	}
	cout << endl;
}