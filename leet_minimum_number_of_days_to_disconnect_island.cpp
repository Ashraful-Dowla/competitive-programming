/*
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[35][35];

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<int>>& grid, int i, int j) {

	vis[i][j] = true;

	for (auto d : directions) {
		int dx = i + d.first;
		int dy = j + d.second;

		if (!isValid(dx, dy) || vis[dx][dy] || grid[dx][dy] == 0) {
			continue;
		}

		dfs(grid, dx, dy);
	}
}

int minDays(vector<vector<int>>& grid) {

	n = grid.size();
	m = grid[0].size();

	int iland = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			iland += grid[i][j];
		}
	}

	int ct = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] && !vis[i][j]) {
				dfs(grid, i, j);
				ct++;
			}
		}
	}

	if (ct > 1) {
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j]) {
				memset(vis, false, sizeof(vis));
				vis[i][j] = true;
				int c = 0;
				for (auto d : directions) {
					int dx = i + d.first;
					int dy = j + d.second;

					if (!isValid(dx, dy) || vis[dx][dy] || grid[dx][dy] == 0) {
						continue;
					}

					c++;
					dfs(grid, dx, dy);
				}

				if (c != 1) {
					return 1;
				}
			}
		}
	}

	return min(2, iland);
}

int main() {

	vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
	// vector<vector<int>> grid = {{1, 1}};

	cout << minDays(grid) << endl;
}