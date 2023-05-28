/*
https://leetcode.com/problems/n-queens/description/
*/
#include <bits/stdc++.h>
using namespace std;

int ans;
bool taken[10][10];

bool isValid(int n, int x, int y) {

	for (int row = 0; row < x; ++row) {
		if (taken[row][y]) {
			return false;
		}
	}

	int row = x, col = y;

	while (row >= 0 && col >= 0) {
		if (taken[row][col]) {
			return false;
		}
		row--, col--;
	}

	row = x, col = y;

	while (row >= 0 && col < n) {
		if (taken[row][col]) {
			return false;
		}
		row--, col++;
	}

	return true;
}

void nqueen(int n, int x) {

	if (x == n) {
		ans++;
		return ;
	}

	for (int col = 0; col < n; ++col) {
		if (isValid(n, x, col)) {
			taken[x][col] = true;
			nqueen(n, x + 1);
			taken[x][col] = false;
		}
	}
}

int totalNQueens(int n) {
	nqueen(n, 0);
	return ans;
}

int main() {
	
	int n = 4;
	cout << totalNQueens(n) << endl;
}