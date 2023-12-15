/*
https://atcoder.jp/contests/abc332/tasks/abc332_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int a[n + 1][m + 1], b[n + 1][m + 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> b[i][j];
		}
	}

	int p[n + 1], q[m + 1];

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}

	for (int i = 1; i <= m; ++i) {
		q[i] = i;
	}

	int ans = 1e9;
	do {
		do {

			bool ok = true;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (a[p[i]][q[j]] == b[i][j]) {
						continue;
					}
					ok = false;
					break;
				}
				if (!ok) break;
			}

			if (!ok) continue;

			int pc = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (p[i] > p[j]) {
						pc++;
					}
				}
			}

			int qc = 0;
			for (int i = 1; i <= m; ++i) {
				for (int j = i + 1; j <= m; ++j) {
					if (q[i] > q[j]) {
						qc++;
					}
				}
			}

			ans = min(ans, pc + qc);

		} while (next_permutation(q + 1, q + m + 1));

	} while (next_permutation(p + 1, p + n + 1));

	cout << (ans == 1e9 ? -1 : ans) << endl;
}