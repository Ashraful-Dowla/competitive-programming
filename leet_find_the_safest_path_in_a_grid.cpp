/*
https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2024-05-15
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int dis[500][500];

vector<pair<int, int>> directions = {
	{1, 0},
	{ -1, 0},
	{0, 1},
	{0, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool bfs(vector<vector<int>>& grid, int i, int j, int ft) {

	queue<pair<int, int>> q;
	vector<vector<bool>> vis(n, vector<bool>(n, false));

	if (grid[i][j] == 0 && dis[i][j] >= ft) {
		q.push({i, j});
		vis[i][j] = true;
	}

	while (!q.empty()) {

		auto p = q.front();
		q.pop();

		if (p.first == n - 1 && p.second == n - 1) {
			return true;
		}

		for (auto d : directions) {
			int x = p.first + d.first;
			int y = p.second + d.second;

			if (!isValid(x, y) || vis[x][y] || grid[x][y] == 1
			        || dis[x][y] < ft) {
				continue;
			}

			q.push({x, y});
			vis[x][y] = true;
		}
	}

	return false;
}

void dis_calc(vector<vector<int>>& grid) {

	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 1) {
				q.push({0, {i, j}});
				dis[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		for (auto d : directions) {
			int x = p.second.first + d.first;
			int y = p.second.second + d.second;

			if (!isValid(x, y) || grid[x][y] == 1) {
				continue;
			}

			if (dis[x][y] > p.first + 1) {
				q.push({p.first + 1, {x, y}});
				dis[x][y] =  p.first + 1;
			}
		}
	}
}


int maximumSafenessFactor(vector<vector<int>>& grid) {

	n = grid.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dis[i][j] = INT_MAX;
		}
	}

	dis_calc(grid);

	int lo = 0, hi = 2 * n, ans = 0;

	while (lo <= hi)	{
		int mid = (lo + hi) / 2;

		if (bfs(grid, 0, 0, mid)) {
			ans = max(ans, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	return ans;
}

int main() {

	// vector<vector<int>> grid = {
	// 	{0, 0, 0, 1},
	// 	{0, 0, 0, 0},
	// 	{0, 0, 0, 0},
	// 	{1, 0, 0, 0}
	// };

	// vector<vector<int>> grid = {
	// 	{1, 0, 0},
	// 	{0, 0, 0},
	// 	{0, 0, 1},
	// };

	// vector<vector<int>> grid = {
	// 	{0, 0, 1},
	// 	{0, 0, 0},
	// 	{0, 0, 0},
	// };

	vector<vector<int>> grid = {
		{0, 1, 1},
		{0, 0, 0},
		{0, 0, 0},
	};

	cout << maximumSafenessFactor(grid) << endl;
}