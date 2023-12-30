/*
https://atcoder.jp/contests/abc301/tasks/abc301_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i + 1 < n; ++i) {

		if (abs(a[i] - a[i + 1]) == 1) {
			cout << a[i] << " ";
		}
		else if (a[i] < a[i + 1]) {
			for (int j = 0; a[i] + j < a[i + 1]; ++j) {
				cout << a[i] + j << " ";
			}
		}
		else {
			for (int j = 0; a[i] - j > a[i + 1]; ++j) {
				cout << a[i] - j << " ";
			}
		}
	}

	cout << a[n - 1] << endl;
}