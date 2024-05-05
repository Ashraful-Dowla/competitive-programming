/*
https://leetcode.com/problems/minimum-falling-path-sum-ii/description/?envType=daily-question&envId=2024-04-26
*/
#include <bits/stdc++.h>
using namespace std;

int dp[300][300];

int solve(vector<vector<int>>& grid, int r, int c) {

	if (r == grid.size()) {
		return 0;
	}
	if (dp[r][c + 1] != -1) {
		return dp[r][c + 1];
	}

	int ans = 1e6;
	for (int i = 0; i < grid.size(); ++i) {
		if (i != c) {
			ans = min(ans, solve(grid, r + 1, i) + grid[r][i]);
		}
	}

	return dp[r][c + 1] = ans;

}

int minFallingPathSum(vector<vector<int>>& grid) {

	for (int i = 0; i <= grid.size() + 2; ++i) {
		for (int j = 0; j <= grid.size() + 2; ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(grid, 0, -1);
}

int main() {

	// vector<vector<int>> grid = {
	// 	{1, 2, 3},
	// 	{4, 5, 6},
	// 	{7, 8, 9}
	// };

	vector<vector<int>> grid = {
		{7}
	};

	cout << minFallingPathSum(grid) << endl;
}