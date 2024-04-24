/*
https://atcoder.jp/contests/abc350/tasks/abc350_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int d = stoi(s.substr(3, 3));

	if (d == 0 || d == 316 || d >= 350) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}