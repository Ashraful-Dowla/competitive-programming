/*
https://atcoder.jp/contests/abc293/tasks/abc293_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	s = "s" + s;

	for (int i = 1; 2 * i < s.size(); ++i) {
		swap(s[2 * i - 1], s[2 * i]);
	}

	for (int i = 1; i < s.size(); ++i) {
		cout << s[i];
	}
	cout << endl;
}