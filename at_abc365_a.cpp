/*
https://atcoder.jp/contests/abc365/tasks/abc365_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int y;
	cin >> y;

	if (y % 4 != 0) {
		cout << 365 << endl;
	}
	else if (y % 100 != 0) {
		cout << 366 << endl;
	}
	else if (y % 400 != 0) {
		cout << 365 << endl;
	}
	else {
		cout << 366 << endl;
	}
}