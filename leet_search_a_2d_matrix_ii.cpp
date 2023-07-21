/*
https://leetcode.com/problems/search-a-2d-matrix-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; ++i) {

		int lo = 0, hi = m - 1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (matrix[i][mid] == target) {
				return true;
			}
			if (matrix[i][mid] < target) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
	}

	return false;
}

int main() {

	int target = -1;
	vector<vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};

	cout << searchMatrix(matrix, target);
}