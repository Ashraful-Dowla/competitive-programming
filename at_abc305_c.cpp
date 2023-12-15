/*
https://atcoder.jp/contests/abc305/tasks/abc305_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	char ch[n][m];

	int u = 1e8, d = -1e8, l = 1e8, r = - 1e8;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == '#') {
				u = min(u, i), d = max(d, i);
				l = min(l, j), r = max(r, j);
			}
		}
	}

	for (int i = u; i <= d; ++i) {
		for (int j = l; j <= r; ++j) {
			if (ch[i][j] == '.') {
				cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}
}