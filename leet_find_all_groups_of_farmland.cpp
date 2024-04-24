/*
https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20
*/
#include <bits/stdc++.h>
using namespace std;

bool vis[400][400];
int n, m, mxx, mxy;
vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j, vector<vector<int>>& land) {

	vis[i][j] = true;

	mxx = max(mxx, i);
	mxy = max(mxy, j);

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || vis[x][y] || land[x][y] == 0) {
			continue;
		}

		dfs(x, y, land);
	}
}

vector<vector<int>> findFarmland(vector<vector<int>>& land) {

	n = land.size();
	m = land[0].size();

	vector<vector<int>> ans;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && land[i][j]) {
				mxx = -1, mxy = -1;

				dfs(i, j, land);

				ans.push_back({i, j, mxx, mxy});
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
	// vector<vector<int>> land = {{1, 1}, {1, 1}};
	// vector<vector<int>> land = {{0}};

	auto res = findFarmland(land);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	}
}