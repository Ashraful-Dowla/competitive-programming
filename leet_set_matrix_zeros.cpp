#include <bits/stdc++.h>
using namespace std;

int n, m;

void betterSolution(vector<vector<int>>& matrix) {
	n = matrix.size();
	m = matrix[0].size();

	vector<bool> row(n, true), col(m, true);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == 0) {
				row[i] = false;
				col[j] = false;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!row[i] ||  !col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}

void optimalSolution(vector<vector<int>>& matrix) {
	n = matrix.size();
	m = matrix[0].size();

	int col = 1;

	for (int i = 0; i < n; ++i) {
		if (matrix[i][0] == 0) col = 0;
		for (int j = 1; j < m; ++j) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 1; --j) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
		if (col == 0) matrix[i][0] = 0;
	}
}

void setZeroes(vector<vector<int>>& matrix) {
	// betterSolution(matrix);
	optimalSolution(matrix);
}

int main() {
	vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	// vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

	setZeroes(matrix);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}