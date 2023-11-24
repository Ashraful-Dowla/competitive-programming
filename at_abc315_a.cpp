/*
https://atcoder.jp/contests/abc315/tasks/abc315_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	for (char ch : s) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			continue;
		}
		cout << ch;
	}
}