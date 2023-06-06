/*
https://leetcode.com/problems/search-a-2d-matrix/description/
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;

bool searchRowMatrix(vector<vector<int>> & matrix, int target, int row) {
	int lo = 0, hi = m - 1;

	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (matrix[row][mid] <= target) {
			lo = mid;
		}
		else hi = mid - 1;
	}

	return matrix[row][lo] == target || matrix[row][hi] == target;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	n = matrix.size();
	m = matrix[0].size();

	int lo = 0, hi = n - 1;

	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (matrix[mid][m - 1] <= target) lo = mid;
		else hi = mid;
	}

	if (searchRowMatrix(matrix, target, lo)) return true;
	else if (searchRowMatrix(matrix, target, hi)) return true;
	else return false;
}

int main() {
	// vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	vector<vector<int>> matrix = {{1, 3, 5, 7}};
	int target = 6;

	cout << searchMatrix(matrix, target);
}