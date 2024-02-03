/*
https://atcoder.jp/contests/abc294/tasks/abc294_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int a[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0) {
				cout << ".";
			}
			else {
				cout << char(a[i][j] + 64);
			}
		}
		cout << endl;
	}
}