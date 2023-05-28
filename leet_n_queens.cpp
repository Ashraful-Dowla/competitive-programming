/*
https://leetcode.com/problems/n-queens-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
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

void solved(int n) {

	vector<string> res;
	for (int i = 0; i < n; ++i) {
		string s = "";
		for (int j = 0; j < n; ++j) {
			if (taken[i][j]) s.push_back('Q');
			else s.push_back('.');
		}
		res.push_back(s);
	}

	ans.push_back(res);
}

void nqueen(int n, int x) {

	if (x == n) {
		solved(n);
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

vector<vector<string>> solveNQueens(int n) {
	nqueen(n, 0);
	return ans;
}

int main() {
	int n = 5;

	vector<vector<string>> res = solveNQueens(n);

	for (auto s : res) {
		for (auto ch : s) {
			cout << ch << endl;
		}
		cout << endl;
	}
}