/*
https://leetcode.com/problems/surrounded-regions/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool visited[205][205];

vector<pair<int, int>> directions = {
	{0, -1},
	{0, 1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y, int n, int m) {
	return x > 0 && x < n && y > 0 && y < m;
}

void matrix(vector<vector<char>>&board, int n, int m, int x, int y) {

	visited[x][y] = true;
	board[x][y] = 'S';

	for (auto d : directions) {
		int _x = x + d.first;
		int _y = y + d.second;

		if (!isValid(_x, _y, n, m) ||
		        visited[_x][_y] || board[_x][_y] == 'X') continue;

		matrix(board, n, m, _x, _y);
	}

}

void solve(vector<vector<char>>& board) {
	int n = board.size();
	int m = board[0].size();

	for (int i = 0; i < m; ++i) {
		if (board[0][i] == 'O') {
			matrix(board, n, m, 0, i);
		}
		if (board[n - 1][i] == 'O') {
			matrix(board, n, m, n - 1, i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (board[i][0] == 'O') {
			matrix(board, n, m, i, 0);
		}
		if (board[i][m - 1] == 'O') {
			matrix(board, n, m, i, m - 1);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
			else if (board[i][j] == 'S') {
				board[i][j] = 'O';
			}
		}
	}

}

int main() {

	// vector<vector<char>> board = {
	// 	{'X', 'X', 'X', 'X'},
	// 	{'X', 'O', 'O', 'X'},
	// 	{'X', 'X', 'O', 'X'},
	// 	{'X', 'O', 'X', 'X'}
	// };

	vector<vector<char>> board = {
		{'O', 'X', 'X', 'O', 'X'},
		{'X', 'O', 'O', 'X', 'O'},
		{'X', 'O', 'X', 'O', 'X'},
		{'O', 'X', 'O', 'O', 'O'},
		{'X', 'X', 'O', 'X', 'O'}
	};


	solve(board);

	for (auto row : board) {
		for (auto ch : row) {
			cout << ch << " ";
		}
		cout << endl;
	}
}