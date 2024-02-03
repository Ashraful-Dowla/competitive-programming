/*
https://atcoder.jp/contests/abc295/tasks/abc295_b
*/
#include <bits/stdc++.h>
using namespace std;

int dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {

	int n, m;
	cin >> n >> m;

	char ch[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] != '.' && ch[i][j] != '#') {

				int power = ch[i][j] - '0';
				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < m; ++l) {
						if (dis(i, j, k, l) <= power && ch[k][l] == '#') {
							ch[k][l] = '.';
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '#') cout << ch[i][j];
			else cout << '.';
		}
		cout << endl;
	}

}