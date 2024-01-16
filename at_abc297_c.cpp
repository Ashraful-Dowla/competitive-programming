/*
https://atcoder.jp/contests/abc297/tasks/abc297_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	char ch[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			if (ch[i][j] == 'T' && ch[i][j + 1] == 'T') {
				ch[i][j] = 'P';
				ch[i][j + 1] = 'C';
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ch[i][j];
		}
		cout << endl;
	}
}