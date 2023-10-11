#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(N^2)
int counting_subgrid(vector<vector<int>>& matrix) {

	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> row(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			row[i] |= matrix[i][j] << (m - j);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int bits = __builtin_popcount(row[i] & row[j]);
			int count = bits * (bits - 1);
			ans += count / 2;
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> matrix = {
		{0, 1, 0, 0, 1},
		{0, 1, 1, 0, 0},
		{1, 0, 0, 0, 0},
		{0, 1, 1, 0, 1},
		{0, 0, 0, 0, 0}
	};

	cout << counting_subgrid(matrix) << endl;
}