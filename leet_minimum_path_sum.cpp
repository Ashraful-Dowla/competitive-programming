/*
https://leetcode.com/problems/minimum-path-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	int arr[m][n];

	arr[0][0] = grid[0][0];
	for (int i = 1; i < n; ++i) {
		arr[0][i] = arr[0][i - 1] + grid[0][i];
	}

	for (int i = 1; i < m; ++i) {
		arr[i][0] = arr[i - 1][0] + grid[i][0];
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			arr[i][j] = min(arr[i - 1][j], arr[i][j - 1]) + grid[i][j];
		}
	}

	return arr[m - 1][n - 1];
}

int main() {
	// vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};

	cout << minPathSum(grid);
}