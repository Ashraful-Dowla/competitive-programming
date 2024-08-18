/*
https://atcoder.jp/contests/abc366/tasks/abc366_b
*/ 
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> v(n);

	int m = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		int sz = v[i].size();
		m = max(m, sz);
	}

	char ch[m + 5][n + 5];

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			ch[i][j] = '#';
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = n - 1, k = 0; i >= 0; --i, ++k) {
			if (j < v[i].size()) {
				ch[j][k] = v[i][j];
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		bool ok = false;
		for (int j = n - 1; j >= 0; --j) {
			if (ch[i][j] != '#') {
				ok = true;
			}
			else if (ok) {
				ch[i][j] = '*';
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ch[i][j] != '#') {
				cout << ch[i][j];
			}
		}
		cout << endl;
	}
}