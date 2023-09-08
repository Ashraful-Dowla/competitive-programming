#include <bits/stdc++.h>
using namespace std;

struct node
{
	int mx_sum, start, end;
};

// time complexity -> O(n)
node kadane(vector<int>& vec) {

	int mx = 0;
	int current_start = 0;
	int mx_start = -1;
	int mx_end = -1;
	int max_so_far = 0;

	for (int i = 0; i < vec.size(); ++i) {
		max_so_far += vec[i];

		if (max_so_far < 0) {
			max_so_far = 0;
			current_start = i + 1;
		}
		if (mx < max_so_far) {
			mx_start = current_start;
			mx_end = i;
			mx = max_so_far;
		}
	}

	node res;
	res.mx_sum = mx;
	res.start = mx_start;
	res.end = mx_end;

	return res;
}

// time complexity -> O(n^3)
int max_subrary_2d(vector<vector<int>>& matrix) {

	int row = matrix.size();
	int col = matrix[0].size();
	int ans = INT_MIN;
	int left, right, top, down;

	for (int i = 0; i < col; ++i) {

		vector<int> temp(row, 0);
		for (int j = i; j < col; ++j) {

			for (int k = 0; k < row; ++k) {
				temp[k] += matrix[k][j];
			}

			node res = kadane(temp);

			if (ans < res.mx_sum) {
				ans = res.mx_sum;
				left = i;
				right = j;
				top = res.start;
				down = res.end;
			}
		}
	}


	// cout << left << " " << right << " " << top << " " << down << endl;
	return ans;
}

int main() {

	vector<vector<int>> matrix = {
		{ 2,  1, -3, -4,  5},
		{ 0,  6,  3,  4,  1},
		{ 2, -2, -1,  4, -5},
		{ -3,  3,  1,  0,  3}
	};

	// vector<vector<int>> matrix = {
	// 	{5, -4, -3, 4},
	// 	{ -3, -4, 4, 5},
	// 	{5, 1, 5, -4}
	// };

	cout << max_subrary_2d(matrix);
}