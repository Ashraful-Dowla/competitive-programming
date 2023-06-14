/*
https://leetcode.com/problems/maximal-rectangle/description/
*/
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();

	stack<int> stk;

	vector<int> left(n, 0), right(n, 0);

	for (int i = 0; i < n; ++i) {

		while (!stk.empty() && heights[i] <= heights[stk.top()]) {
			stk.pop();
		}

		if (stk.empty()) left[i] = 0;
		else left[i] = stk.top() + 1;

		stk.push(i);
	}

	while (!stk.empty()) {
		stk.pop();
	}

	for (int i = n - 1; i >= 0; --i) {

		while (!stk.empty() && heights[i] <= heights[stk.top()]) {
			stk.pop();
		}

		if (stk.empty()) right[i] = n - 1;
		else right[i] = stk.top() - 1;

		stk.push(i);
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, (right[i] - left[i] + 1) * heights[i]);
	}

	return mx;
}

//time complexity -> O(N*M)
int maximalRectangle(vector<vector<char>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();

	vector<int> heights(m, 0);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0) {
				heights[j] = matrix[i][j] - '0';
			}
			else {
				if (matrix[i][j] == '0') {
					heights[j] = 0;
				}
				else {
					heights[j] += (matrix[i][j] - '0');
				}
			}
		}

		// for (int k = 0; k < m; ++k) {
		// 	cout << heights[k] << " ";
		// }
		// cout << endl;

		ans = max(ans, largestRectangleArea(heights));
	}

	return ans;
}

int main() {
	vector<vector<char>>matrix = {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};

	cout << maximalRectangle(matrix);
}