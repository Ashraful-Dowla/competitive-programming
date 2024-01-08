/*
https://atcoder.jp/contests/abc300/tasks/abc300_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char a[n][m], b[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}


	for (int s = 0; s < n; ++s) {
		for (int t = 0; t < m; ++t) {
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[(i - s + n) % n][(j - t + m) % m] == b[i][j]) {
						continue;
					}
					ok = false;
					break;
				}
			}

			if (ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

}