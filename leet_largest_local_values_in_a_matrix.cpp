/*
https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
*/
#include <bits/stdc++.h>
using namespace std;

int find_max(vector<vector<int>>& grid, int k, int q) {

	int mx = 0;
	for (int i = k; i < k + 3; i++) {
		for (int j = q; j < q + 3; ++j) {
			mx = max(mx, grid[i][j]);
		}
	}

	return mx;
}

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

	int n = grid.size();

	vector<vector<int>> ans(n - 2, vector<int>(n - 2));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i + 2 < n && j + 2 < n) {
				ans[i][j] = find_max(grid, i, j);
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> grid = {
		{9, 9, 8, 1},
		{5, 6, 2, 6},
		{8, 2, 6, 4},
		{6, 2, 2, 2}
	};


	auto res = largestLocal(grid);

	for (auto v : res) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}