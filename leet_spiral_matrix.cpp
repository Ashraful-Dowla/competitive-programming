/*
https://leetcode.com/problems/spiral-matrix/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool taken[12][12];

bool isValid(int n, int m, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	int x = 0, y = 0, ok = 0;
	vector<int> ans;

	while (ans.size() != n * m) {
		while (isValid(n, m, x, y) && !taken[x][y]) {
			ans.push_back(matrix[x][y]);
			taken[x][y] = true;

			if (ok == 0) y++;
			else if (ok == 1) x++;
			else if (ok == 2) y--;
			else x--;
		}

		if (ok == 0) y--, x++;
		else if (ok == 1) x--, y--;
		else if (ok == 2) y++, x--;
		else x++, y++;

		ok++;
		ok %= 4;
	}

	return ans;
}

int main() {
	// vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	// vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

	vector<int> ans = spiralOrder(matrix);

	for (int x : ans) {
		cout << x << " ";
	}
}