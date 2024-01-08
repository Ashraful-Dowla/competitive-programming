/*
https://atcoder.jp/contests/abc299/tasks/abc299_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 2) {
		cout << "! " << 1 << endl;
		return 0;
	}

	int lo = 1, hi = n;

	while (hi - lo > 1) {

		int mid = (lo + hi) / 2;

		cout << "? " << mid << endl;
		cout << flush;

		int s;
		cin >> s;

		if (s == 1) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}

	cout << "! " << lo << endl;
}