/*
https://leetcode.com/problems/search-a-2d-matrix-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	int n = matrix.size();
	int m = matrix[0].size();

	int row = 0;
	int col = m - 1;

	while (row < n && col >= 0) {
		if (matrix[row][col] == target) {
			return true;
		}
		if (matrix[row][col] > target) {
			col--;
		}
		else {
			row++;
		}
	}

	return false;
}

int main() {

	int target = 5;
	vector<vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};

	cout << searchMatrix(matrix, target);
}