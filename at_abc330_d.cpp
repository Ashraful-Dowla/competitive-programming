/*
https://atcoder.jp/contests/abc330/tasks/abc330_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	char ch[n][n];
	vector<ll> row(n, 0), col(n, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == 'o') {
				row[i]++;
				col[j]++;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ch[i][j] == 'o') {
				ans += (row[i] - 1) * (col[j] - 1);
			}
		}
	}

	cout << ans << endl;
}