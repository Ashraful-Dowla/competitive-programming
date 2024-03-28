/*
https://www.spoj.com/problems/BYTESM2/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int a[n][m];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < m; ++j) {

				int mx = a[i - 1][j];
				if (j - 1 >= 0) {
					mx = max(mx, a[i - 1][j - 1]);
				}
				if (j + 1 < m) {
					mx = max(mx, a[i - 1][j + 1]);
				}
				a[i][j] += mx;
			}
		}

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			ans = max(ans, a[n - 1][i]);
		}
		cout << ans << endl;
	}
}