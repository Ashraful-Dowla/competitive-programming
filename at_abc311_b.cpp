/*
https://atcoder.jp/contests/abc311/tasks/abc311_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int col[m] = {0};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;

			if (ch == 'o') {
				col[j]++;
			}
		}
	}

	int ans = 0, cnt = 0;
	if (col[0] == n) {
		ans = max(ans, ++cnt);
	}

	for (int i = 1; i < m; ++i) {
		if (col[i] == n && col[i - 1] == n) {
			ans = max(ans, ++cnt);
		}
		else {
			ans = max(ans, cnt);
			cnt = col[i] == n;
		}
	}

	cout << max(ans, cnt) << endl;
}