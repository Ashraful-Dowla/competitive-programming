/*
https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
*/
#include <bits/stdc++.h>
using namespace std;

int numMagicSquaresInside(vector<vector<int>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	if (n < 3 || m < 3) {
		return 0;
	}

	int ans = 0;
	for (int i = 0; i + 2 < n; ++i) {
		for (int j = 0; j + 2 < m; ++j) {
			vector<int> row(3, 0), col(3, 0);
			set<int> nums;
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					int x = i + k, y = j + l;
					row[k] += grid[x][y];
					col[l] += grid[x][y];

					nums.insert(grid[x][y]);
				}
			}

			int diag1 = 0, diag2 = 0;
			int x = i, y = j;
			for (int p = 0; p < 3; ++p) {
				diag1 += grid[x][y];
				x++, y++;
			}

			x = i, y = j + 2;
			for (int p = 0; p < 3; ++p) {
				diag2 += grid[x][y];
				x++, y--;
			}

			bool ok = true;
			for (int k = 1; k <= 9; ++k) {
				if (nums.find(k) == nums.end()) {
					ok = false;
					break;
				}
			}

			if (ok) {
				set<int>s;
				for (int k = 0; k < 3; ++k) {
					s.insert(row[k]);
					s.insert(col[k]);
				}
				s.insert(diag1);
				s.insert(diag2);

				if (s.size() == 1) {
					ans++;
				}
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
	// vector<vector<int>> grid = {{8}};
	// vector<vector<int>> grid = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};


	cout << numMagicSquaresInside(grid) << endl;
}