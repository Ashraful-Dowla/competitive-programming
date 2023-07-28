/*
https://leetcode.com/problems/sudoku-solver/description/
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<char>>row, col, grid;

int findGrid(int x, int y) {

	int cnt = 0;
	if (x >= 3 && x < 6) cnt = 3;
	else if (x >= 6) cnt = 6;

	if (y >= 3 && y < 6) cnt += 1;
	else if (y >= 6) cnt += 2;

	return cnt;
}

bool solve(vector<vector<char>>& board) {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') {
				for (char num = '1'; num <= '9'; ++num) {

					bool r = row[i].find(num) == row[i].end();
					bool c = col[j].find(num) == col[j].end();

					int g = findGrid(i, j);
					bool gr = grid[g].find(num) == grid[g].end();

					if (r & c & gr) {
						row[i].insert(num);
						col[j].insert(num);
						grid[g].insert(num);
						board[i][j] = num;

						bool isPossible = solve(board);

						if (isPossible) {
							return true;
						}
						else {
							board[i][j] = '.';
							row[i].erase(num);
							col[j].erase(num);
							grid[g].erase(num);
						}
					}
				}
				return false;
			}
		}
	}

	return true;
}

void solveSudoku(vector<vector<char>>& board) {

	for (int i = 0; i <= 9; ++i) {
		set<char> s;
		row.push_back(s);
		col.push_back(s);
		grid.push_back(s);
	}

	n = board.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') continue;

			char num = board[i][j];
			row[i].insert(num);
			col[j].insert(num);
			grid[findGrid(i, j)].insert(num);
		}
	}

	solve(board);
}

int main() {

	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	solveSudoku(board);


	for (auto b : board) {
		for (char ch : b) {
			cout << ch << " ";
		}
		cout << endl;
	}
}