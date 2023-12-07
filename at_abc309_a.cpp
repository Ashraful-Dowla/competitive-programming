/*
https://atcoder.jp/contests/abc309/tasks/abc309_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	if (a == 1 && b == 2 || a == 2 && b == 3) {
		cout << "Yes" << endl;
	}
	else if (a == 4 && b == 5 || a == 5 && b == 6) {
		cout << "Yes" << endl;
	}
	else if (a == 7 && b == 8 || a == 8 && b == 9) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}