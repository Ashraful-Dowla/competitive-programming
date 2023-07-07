/*
https://leetcode.com/problems/number-of-islands/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool visited[305][305];
int res, m, n;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0},
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<char>>& grid, int x, int y) {

	visited[x][y] = true;

	for (auto d : directions) {
		int _x = x + d.first;
		int _y = y + d.second;

		if (!isValid(_x, _y) || visited[_x][_y]
		        || grid[_x][_y] == '0') continue;

		dfs(grid, _x, _y);
	}
}


int numIslands(vector<vector<char>>& grid) {
	n = grid.size();
	m = grid[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '1' && !visited[i][j]) {
				dfs(grid, i, j);
				res++;
			}
		}
	}

	return res;
}

int main() {
	// vector<vector<char>> grid = {
	// 	{'1', '1', '1', '1', '0'},
	// 	{'1', '1', '0', '1', '0'},
	// 	{'1', '1', '0', '0', '0'},
	// 	{'0', '0', '0', '0', '0'}
	// };

	vector<vector<char>> grid =  {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};

	cout << numIslands(grid);
}