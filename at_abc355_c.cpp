/*
https://atcoder.jp/contests/abc355/tasks/abc355_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, t;
	cin >> n >> t;


	int a[n + 1][n + 1];

	map<int, pair<int, int>> mp;
	for (int i = 1, k = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = k;
			mp[k] = {i, j};
			k++;
		}
	}

	set<int> d1, d2;
	for (int i = 1; i <= n; ++i) {
		d1.insert(a[i][i]);
	}

	for (int i = n, j = 1; i >= 1; --i, ++j) {
		d2.insert(a[i][j]);
	}

	vector<int> row(n + 1, n), col(n + 1, n), diag(2, n);

	for (int i = 0; i < t; ++i) {
		int q;
		cin >> q;

		int x = mp[q].first;
		int y = mp[q].second;

		row[x]--;
		col[y]--;

		if (d1.find(q) != d1.end()) {
			diag[0]--;
		}
		if (d2.find(q) != d2.end()) {
			diag[1]--;
		}

		if (row[x] <= 0 || col[y] <= 0  || diag[0] <= 0 || diag[1] <= 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}