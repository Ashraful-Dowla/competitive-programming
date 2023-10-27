/*
https://leetcode.com/problems/diagonal-traverse/
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int m, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

	int n = mat.size();
	int m = mat[0].size();

	vector<int> ans;

	int r = 0, c = 0;
	for (int i = 0; i < n + m - 1; ++i) {

		if (i % 2 == 0) {
			while (isValid(n, m, r, c)) {
				ans.push_back(mat[r][c]);
				r--, c++;
			}
			r++, c--;

			if (isValid(n, m, r, c + 1)) {
				c++;
			}
			else {
				r++;
			}
		}
		else {
			while (isValid(n, m, r, c)) {
				ans.push_back(mat[r][c]);
				r++, c--;
			}
			r--, c++;

			if (isValid(n, m, r + 1, c)) {
				r++;
			}
			else {
				c++;
			}
		}
	}

	return ans;
}

int main() {

}