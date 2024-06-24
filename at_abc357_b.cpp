/*
https://atcoder.jp/contests/abc357/tasks/abc357_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	int lo = 0, up = 0;

	for (char ch : s) {
		if (ch >= 'A' && ch <= 'Z') {
			up++;
		}
		else {
			lo++;
		}
	}

	if (up > lo) {
		for (char &ch : s) {
			ch = toupper(ch);
		}
	}
	else {
		for (char &ch : s) {
			ch = tolower(ch);
		}
	}

	cout << s << endl;
}