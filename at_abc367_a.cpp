/*
https://atcoder.jp/contests/abc367/tasks/abc367_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	if (b <= c) {
		if (b <= a && a <= c) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	else {
		for (int x = b; x <= b + c; ++x) {
			if (x % 24 == a) {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
}