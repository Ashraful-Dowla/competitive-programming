/*
https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int islandPerimeter(vector<vector<int>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				for (auto d : directions) {
					int x = i + d.first;
					int y = j + d.second;
					if (!isValid(x, y, n, m) || grid[x][y] == 0) {
						ans++;
					}
				}
			}
		}
	}

	return ans;
}

int main() {

	// vector<vector<int>> grid  = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
	// vector<vector<int>> grid  = {{1}};
	vector<vector<int>> grid  = {{1, 0}};

	cout << islandPerimeter(grid) << endl;
}