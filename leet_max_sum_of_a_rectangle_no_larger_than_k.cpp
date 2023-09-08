/*
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
*/
#include <bits/stdc++.h>
using namespace std;

//time complexity-> O(col*col*row*log(row))
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

	int n = matrix.size();
	int m = matrix[0].size();
	int ans = INT_MIN;

	for (int i = 0; i < m; ++i) {

		vector<int> temp(n, 0);
		for (int j = i; j < m; ++j) {

			for (int l = 0; l < n; ++l) {
				temp[l] += matrix[l][j];
			}

			set<int> pf;
			pf.insert(0);

			int sum = 0;
			for (int x : temp) {
				sum += x;
				auto it = pf.lower_bound(sum - k);

				if (it != pf.end()) {
					ans = max(ans, sum - *it);
				}
				pf.insert(sum);
			}
		}
	}

	return ans;
}

int main() {

	// vector<vector<int>> matrix = {
	// 	{1, 0, 1},
	// 	{0, -2, 3}
	// };

	// int k = 2;

	// vector<vector<int>> matrix = {
	// 	{2, 2, -1}
	// };
	// int k = 3;

	// vector<vector<int>> matrix = {
	// 	{2, 2, -1}
	// };
	// int k = 0;

	vector<vector<int>> matrix = {
		{5, -4, -3, 4},
		{ -3, -4, 4, 5},
		{5, 1, 5, -4}
	};
	int k = 10;

	cout << maxSumSubmatrix(matrix, k);
}