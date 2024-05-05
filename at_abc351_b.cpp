/*
https://atcoder.jp/contests/abc351/tasks/abc351_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	char a[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	char b[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> b[i][j];
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != b[i][j]) {
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
	}
}