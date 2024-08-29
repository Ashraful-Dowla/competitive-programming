/*
https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28
*/
#include <bits/stdc++.h>
using namespace std;

bool vis[505][505], chk;
int n, m;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {

	vis[x][y] = true;
	if (grid1[x][y] == 0) {
		chk = false;
	}

	for (auto d : directions) {

		int dx = x + d.first;
		int dy = y + d.second;

		if (!isValid(dx, dy) || vis[dx][dy] || grid2[dx][dy] == 0) {
			continue;
		}

		dfs(grid1, grid2, dx, dy);
	}
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

	n = grid1.size();
	m = grid1[0].size();

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid2[i][j] == 1 && !vis[i][j]) {
				chk = true;
				dfs(grid1, grid2, i, j);
				ans += chk;
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> grid1 = {
		{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}
	};
	vector<vector<int>> grid2 = {
		{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1},
		{0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}
	};

	cout << countSubIslands(grid1, grid2) << endl;

}