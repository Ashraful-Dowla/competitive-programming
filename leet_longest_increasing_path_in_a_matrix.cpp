/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, dp[205][205];
bool visited[205][205];

vector<pair<int, int>> directions = {
	{1, 0},
	{ -1, 0},
	{0, 1},
	{0, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int solve(vector<vector<int>>& matrix, int i, int j) {

	if (dp[i][j] != -1) return dp[i][j];

	int ans = 0;
	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || visited[x][y] || matrix[i][j] >= matrix[x][y]) {
			continue;
		}

		visited[x][y] = true;
		ans = max(ans, solve(matrix, x, y) + 1);
		visited[x][y] = false;
	}

	return dp[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {

	n = matrix.size();
	m = matrix[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = -1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = true;
			ans = max(ans, solve(matrix, i, j) + 1);
			visited[i][j] = false;
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
	// vector<vector<int>> matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

	cout << longestIncreasingPath(matrix) << endl;
}