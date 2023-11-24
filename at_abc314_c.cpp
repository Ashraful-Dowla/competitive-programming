/*
https://atcoder.jp/contests/abc314/tasks/abc314_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<int> c[m + 1], p[m + 1];

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		c[x].push_back(i);
		p[x].push_back(i);
	}

	for (int i = 1; i <= m; ++i) {

		int sz = c[i].size();
		int last = c[i][sz - 1];

		for (int j = sz - 1; j >= 0; --j) {
			c[i][j] = c[i][j - 1];
		}

		c[i][0] = last;
	}

	char ans[n];
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < c[i].size(); ++j) {
			ans[p[i][j]] = s[c[i][j]];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i];
	}
	cout << endl;
}