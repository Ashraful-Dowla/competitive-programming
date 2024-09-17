/*
https://atcoder.jp/contests/abc274/tasks/abc274_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	char ch[n][m];

	vector<int> x(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] == '#') {
				x[j]++;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << x[i] << " ";
	}
	cout << endl;
}