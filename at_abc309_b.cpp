/*
https://atcoder.jp/contests/abc309/tasks/abc309_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	char ch[n][n], ans[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch[i][j];
			ans[i][j] = ch[i][j];
		}
	}


	for (int i = 1; i < n; ++i) {
		ans[0][i] = ch[0][i - 1];
	}

	for (int i = 1; i < n; ++i) {
		ans[i][n - 1] = ch[i - 1][n - 1];
	}

	for (int i = n - 2; i >= 0; --i) {
		ans[n - 1][i] = ch[n - 1][i + 1];
	}

	for (int i = n - 2; i >= 0; --i) {
		ans[i][0] = ch[i + 1][0];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}