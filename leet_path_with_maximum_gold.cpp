/*
https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, gold, ans;
bool vis[20][20];

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(vector<vector<int>>& grid, int i, int j) {

	ans = max(ans, gold);

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || vis[x][y] || grid[x][y] == 0) {
			continue;
		}

		vis[x][y] = true;
		gold += grid[x][y];

		solve(grid, x, y);

		vis[x][y] = false;
		gold -= grid[x][y];
	}

}


int getMaximumGold(vector<vector<int>>& grid) {

	n = grid.size();
	m = grid[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j]) {

				vis[i][j] = true;
				gold += grid[i][j];

				solve(grid, i, j);

				vis[i][j] = false;
				gold -= grid[i][j];
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> grid = {
		{0, 6, 0},
		{5, 8, 7},
		{0, 9, 0}
	};

	cout << getMaximumGold(grid) << endl;
}