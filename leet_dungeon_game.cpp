/*
https://leetcode.com/problems/dungeon-game/description/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[205][205], n, m;

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	n = dungeon.size();
	m = dungeon[0].size();

	for (int r = n - 1; r >= 0; r--) {
		for (int c = m - 1; c >= 0; c--) {
			bool right = isValid(r, c + 1);
			bool down = isValid(r + 1, c);

			if (right && down) {
				dp[r][c] = min(0, dungeon[r][c] + max(dp[r][c + 1], dp[r + 1][c]));
			}
			else if (right) {
				dp[r][c] = min(0, dungeon[r][c] + dp[r][c + 1]);
			}
			else if (down) {
				dp[r][c] = min(0, dungeon[r][c] + dp[r + 1][c]);
			}
			else {
				dp[r][c] = min(0, dungeon[r][c]);
			}
		}
	}


	return abs(dp[0][0]) + 1;
}

int main() {
	// vector<vector<int>> dungeon = {{ -2, -3, 3}, { -5, -10, 1}, {10, 30, -5}};
	// vector<vector<int>> dungeon = {{0}};
	vector<vector<int>> dungeon = {{ -3, 5}};

	cout << calculateMinimumHP(dungeon);
}