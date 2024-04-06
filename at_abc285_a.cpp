/*
https://atcoder.jp/contests/abc285/tasks/abc285_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	if (2 * a == b || 2 * a + 1 == b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}