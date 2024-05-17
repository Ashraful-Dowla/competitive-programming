/*
https://atcoder.jp/contests/abc282/tasks/abc282_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	bool t = false;
	for (char &ch : s) {
		if (ch == '"') {
			t ^= 1;
		}
		if (!t && ch == ',') {
			ch = '.';
		}
	}

	cout << s << endl;
}