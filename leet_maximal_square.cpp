/*
https://leetcode.com/problems/maximal-square/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[305][305];

int maximalSquare(vector<vector<char>>& matrix) {

	int n = matrix.size();
	int m = matrix[0].size();

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i][0] = matrix[i][0] - '0';
		ans = max(ans, dp[i][0]);
	}

	for (int i = 0; i < m; ++i) {
		dp[0][i] = matrix[0][i] - '0';
		ans = max(ans, dp[0][i]);
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			int val = matrix[i][j] - '0';
			if (val == 0) continue;

			dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + val;
			ans = max(ans, dp[i][j]);
		}
	}

	return ans * ans;
}

int main() {

	// vector<vector<char>> matrix = {
	// 	{'1', '0', '1', '0', '0'},
	// 	{'1', '0', '1', '1', '1'},
	// 	{'1', '1', '1', '1', '1'},
	// 	{'1', '0', '0', '1', '0'}
	// };

	// vector<vector<char>> matrix = {
	// 	{'0', '1',},
	// 	{'1', '0',},
	// };

	// vector<vector<char>> matrix = {
	// 	{'1', '1', '1', '0'},
	// 	{'1', '0', '1', '1'},
	// 	{'1', '1', '1', '1'},
	// 	{'0', '1', '1', '1'}
	// };

	cout << maximalSquare(matrix);
}