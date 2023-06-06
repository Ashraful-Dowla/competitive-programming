#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	int grid[m][n];

	int c = 1;
	for (int i = 0; i < n; ++i) {
		if (obstacleGrid[0][i] == 1) c = 0;
		grid[0][i] = c;
	}

	c = 1;
	for (int i = 0; i < m; ++i ) {
		if (obstacleGrid[i][0] == 1) c = 0;
		grid[i][0] = c;
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (obstacleGrid[i][j]) {
				grid[i][j] = 0;
				continue;
			}
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return grid[m - 1][n - 1];
}

int main() {
	// vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	// vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
	vector<vector<int>> obstacleGrid = {{1}, {0}};

	cout << uniquePathsWithObstacles(obstacleGrid);
}