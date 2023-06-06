/*
https://leetcode.com/problems/unique-paths/description/
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
	int grid[m + 2][n + 2];

	for (int i = 1; i <= n; ++i) {
		grid[1][i] = 1;
	}

	for (int i = 1; i <= m; ++i) {
		grid[i][1] = 1;
	}

	for (int i = 2; i <= m; ++i) {
		for (int j = 2; j <= n; ++j) {
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}

	return grid[m][n];
}

int main() {
	int m = 3, n = 7;

	cout << uniquePaths(m, n) << endl;
}