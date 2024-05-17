/*
https://leetcode.com/problems/score-after-flipping-matrix/description/?envType=daily-question&envId=2024-05-13
*/
#include <bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j]) {
				a[i] |= (1 << (m - j - 1));
			}
		}
	}

	int t = (1 << m) - 1;

	for (int i = 0; i < n; ++i) {
		if ((a[i]^t) > a[i]) {
			a[i] ^= t;
		}
	}

	for (int j = 0; j < m; ++j) {
		int one = 0;
		for (int i = 0; i < n; ++i) {
			if ((a[i] & (1 << (m - j - 1)))) {
				one++;
			}
		}

		if (n > 2 * one) {
			for (int i = 0; i < n; ++i) {
				a[i] ^= (1 << (m - j - 1));
			}
		}
	}


	int res = accumulate(a.begin(), a.end(), 0);
	return res;
}

int main() {

	vector<vector<int>> grid = {
		{0, 0, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 0}
	};

	cout << matrixScore(grid) << endl;
}