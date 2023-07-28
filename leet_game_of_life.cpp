/*
https://leetcode.com/problems/game-of-life/description/
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> directions = {
	{ -1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
	{ -1, -1},
	{ -1, 1},
	{1, 1},
	{1, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

// 0->1 = 2
// 1->0 = 3
// 0->0 = 4
// 1->1 = 5

void gameOfLife(vector<vector<int>>& board) {

	n = board.size();
	m = board[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			int cnt = 0;
			for (auto d : directions) {
				int x = i + d.first;
				int y = j + d.second;

				if (!isValid(x, y) || board[x][y] == 2 || board[x][y] == 4 || board[x][y] == 0) {
					continue;
				}
				cnt++;
			}

			if (board[i][j]) {
				if (cnt < 2) board[i][j] = 3;
				else if (cnt <= 3) board[i][j] = 5;
				else board[i][j] = 3;
			}
			else {
				if (cnt == 3) board[i][j] = 2;
				else board[i][j] = 4;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (board[i][j] == 2 || board[i][j] == 5) {
				board[i][j] = 1;
			}
			else board[i][j] = 0;
		}
	}
}

int main() {

	// vector<vector<int>> board = {
	// 	{0, 1, 0},
	// 	{0, 0, 1},
	// 	{1, 1, 1},
	// 	{0, 0, 0}
	// };

	vector<vector<int>> board = {
		{1, 1},
		{1, 0},
	};

	gameOfLife(board);

	for (auto b : board) {
		for (int c : b) {
			cout << c << " ";
		}
		cout << endl;
	}
}