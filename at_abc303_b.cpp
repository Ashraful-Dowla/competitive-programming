/*
https://atcoder.jp/contests/abc303/tasks/abc303_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int a[m][n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	map<pair<int, int>, bool> mp;
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			mp[ {a[i][j - 1], a[i][j]}] = true;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (mp[ {i, j}] || mp[ {j, i}]) {
				continue;
			}
			ans++;
		}
	}

	cout << ans << endl;
}