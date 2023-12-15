/*
https://atcoder.jp/contests/abc305/tasks/abc305_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	if (n % 5 == 0) {
		cout << n << endl;
	}
	else {

		int t = n / 5;

		if (abs(n - t * 5) < abs(n - (t + 1) * 5)) {
			cout << t * 5 << endl;
		}
		else {
			cout << (t + 1) * 5 << endl;
		}
	}
}