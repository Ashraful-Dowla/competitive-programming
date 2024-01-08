/*
https://atcoder.jp/contests/abc298/tasks/abc298_b
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[105][105], r[105][105], b[105][105];

void rotote() {

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			r[i][j] = a[n + 1 - j][i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = r[i][j];
		}
	}
}

bool chk() {

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 1) {
				if (b[i][j] == 0) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (chk()) {
			cout << "Yes" << endl;
			return 0;
		}
		else {
			rotote();
		}
	}

	cout << "No" << endl;
}