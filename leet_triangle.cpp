/*
https://leetcode.com/problems/triangle/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[205][205];

int solve(vector<vector<int>>&triangle, int i, int j) {

	if (i == triangle.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX;
	if (j < triangle[i].size()) {
		ans = min(ans, solve(triangle, i + 1, j) + triangle[i][j]);
	}
	if (j + 1 < triangle[i].size()) {
		ans = min(ans, solve(triangle, i + 1, j + 1) + triangle[i][j + 1]);
	}

	return dp[i][j] = ans;
}

int minimumTotal(vector<vector<int>>& triangle) {

	int n = triangle.size();
	int m = triangle[n - 1].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = -1;
		}
	}
	return solve(triangle, 0, 0);
}

int main() {
	// vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	// vector<vector<int>> triangle = {{ -10}};
	vector<vector<int>> triangle = {{ -1}, {2, 3}, {1, -1, -3}};

	cout << minimumTotal(triangle);
}