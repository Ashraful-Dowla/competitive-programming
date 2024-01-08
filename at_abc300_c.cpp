/*
https://atcoder.jp/contests/abc300/tasks/abc300_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n, m;
char ch[N][N];
int res[N];

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			int l = i, r = j, ld = 0;
			while (check(l, r) && ch[l][r] == '#') {
				l++, r++, ld++;
			}

			if (ld < 3 || (ld - 1) % 2) {
				continue;
			}

			l = i, r = j + ld - 1;
			int rd = 0;

			while (check(l, r) && ch[l][r] == '#') {
				l++, r--;
				rd++;
			}

			if (ld == rd) {
				res[(ld - 1) / 2]++;
			}
		}
	}

	for (int i = 1; i <= min(n, m); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}