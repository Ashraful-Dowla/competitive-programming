/*
https://atcoder.jp/contests/abc312/tasks/abc312_b
*/
#include <bits/stdc++.h>
using namespace std;

char ch[105][105];

char top_left[4][4] = {
	{'#', '#', '#', '.'},
	{'#', '#', '#', '.'},
	{'#', '#', '#', '.'},
	{'.', '.', '.', '.'},
};

char bottom_right[4][4] = {
	{'.', '.', '.', '.'},
	{'.', '#', '#', '#'},
	{'.', '#', '#', '#'},
	{'.', '#', '#', '#'},
};

bool check_top_left(int x, int y) {

	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			if (ch[x + i][y + j] == top_left[i][j]) {
				continue;
			}
			return false;
		}
	}

	return true;
}

bool check_bottom_right(int x, int y) {

	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			if (ch[x + i][y + j] == bottom_right[i][j]) {
				continue;
			}
			return false;
		}
	}

	return true;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i + 8 < n; ++i) {
		for (int j = 0; j + 8 < m; ++j) {

			if (check_top_left(i, j) && check_bottom_right(i + 5, j + 5)) {
				cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}
}