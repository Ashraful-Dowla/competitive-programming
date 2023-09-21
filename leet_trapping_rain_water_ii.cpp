/*
https://leetcode.com/problems/trapping-rain-water-ii/
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
	int h, x, y;
};

struct cmp {
	bool operator()(node a, node b) {
		return !(a.h < b.h);
	}
};

int n, m;
priority_queue<node, vector<node>, cmp> pq;
bool visited[205][205];

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int trapRainWater(vector<vector<int>>& heightMap) {

	n = heightMap.size();
	m = heightMap[0].size();

	for (int i = 0; i < m; ++i) {
		if (!visited[0][i]) {
			pq.push({heightMap[0][i], 0, i});
			visited[0][i] = true;
		}
		if (!visited[n - 1][i]) {
			pq.push({heightMap[n - 1][i], n - 1, i});
			visited[n - 1][i] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!visited[i][0]) {
			pq.push({heightMap[i][0], i, 0});
			visited[i][0] = true;
		}
		if (!visited[i][m - 1]) {
			pq.push({heightMap[i][m - 1], i, m - 1});
			visited[i][m - 1] = true;
		}
	}

	int ans = 0;
	while (pq.size() > 0) {
		node v = pq.top();
		pq.pop();

		for (auto d : directions) {
			int x = v.x + d.first;
			int y = v.y + d.second;

			if (!isValid(x, y) || visited[x][y]) {
				continue;
			}

			if (v.h > heightMap[x][y]) {
				ans += v.h - heightMap[x][y];
				heightMap[x][y] = v.h;
			}
			pq.push({heightMap[x][y], x, y});
			visited[x][y] = true;
		}
	}

	return ans;
}

int main() {

	// vector<vector<int>> heightMap = {
	// 	{1, 4, 3, 1, 3, 2},
	// 	{3, 2, 1, 3, 2, 4},
	// 	{2, 3, 3, 2, 3, 1}
	// };

	// vector<vector<int>> heightMap = {
	// 	{3, 3, 3, 3, 3},
	// 	{3, 2, 2, 2, 3},
	// 	{3, 2, 1, 2, 3},
	// 	{3, 2, 2, 2, 3},
	// 	{3, 3, 3, 3, 3}
	// };

	// vector<vector<int>> heightMap = {
	// 	{9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9},
	// 	{9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 9},
	// 	{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
	// 	{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
	// 	{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
	// };

	vector<vector<int>> heightMap = {
		{5, 5, 5, 1},
		{5, 1, 1, 5},
		{5, 1, 5, 5},
		{5, 2, 5, 8}
	};

	cout << trapRainWater(heightMap);
}