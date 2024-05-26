/*
https://atcoder.jp/contests/abc279/tasks/abc279_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	char s[n][m], t[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> t[i][j];
		}
	}

	vector<string> ts(m), tt(m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ts[j].push_back(s[i][j]);
			tt[j].push_back(t[i][j]);
		}
	}

	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());

	if (ts == tt) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}