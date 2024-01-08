/*
https://atcoder.jp/contests/abc335/tasks/abc335_d
*/
#include <bits/stdc++.h>
using namespace std;

int matrix[50][50], n;

int main() {

	cin >> n;

	for (int i = 0; i <= n + 1; ++i) {
		matrix[0][i] = matrix[i][0] = INT_MAX;
		matrix[n + 1][i] = matrix[i][n + 1] = INT_MAX;
	}


	int cnt = 1, x = 1, y = 1;
	while (cnt < n * n) {

		while (matrix[x][y] == 0) {
			matrix[x++][y] = cnt++;
		}

		x--, y++;

		while (matrix[x][y] == 0) {
			matrix[x][y++] = cnt++;
		}

		y--, x--;

		while (matrix[x][y] == 0) {
			matrix[x--][y] = cnt++;
		}

		x++, y--;
		while (matrix[x][y] == 0) {
			matrix[x][y--] = cnt++;
		}

		x++, y++;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (matrix[i][j] == 0) cout << "T ";
			else cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}