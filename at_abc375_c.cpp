/*
https://atcoder.jp/contests/abc375/tasks/abc375_c
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(int n, vector<string>& a) {

	vector<string> b(n, string(n, '#'));

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			b[y - 1][n - x] = a[x - 1][y - 1];
		}
	}

	a = b;
}

int main() {

	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<vector<string>> rot;

	rot.push_back(v);
	rotate(n, v);
	rot.push_back(v);
	rotate(n, v);
	rot.push_back(v);
	rotate(n, v);
	rot.push_back(v);

	for (int i = 1; i * 2 <= n; ++i) {
		int cnt = i % 4;
		for (int j = i; j <= n + 1 - i; ++j) {
			v[i - 1][j - 1] = rot[cnt][i - 1][j - 1];
			v[j - 1][i - 1] = rot[cnt][j - 1][i - 1];
			v[n - i][j - 1] = rot[cnt][n - i][j - 1];
			v[j - 1][n - i] = rot[cnt][j - 1][n - i];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j];
		}
		cout << endl;
	}
}