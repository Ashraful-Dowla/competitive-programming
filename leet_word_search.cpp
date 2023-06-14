/*
https://leetcode.com/problems/word-search/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
	{ -1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int n, m;
bool taken[10][10];

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool solve(vector<vector<char>>& board, string word, int x, int y, int idx) {

	if (idx == word.size()) return true;

	bool isPossible = false;
	for (auto d : directions) {
		int _x = x + d.first;
		int _y = y + d.second;

		if (!isValid(_x, _y) || taken[_x][_y] || board[_x][_y] != word[idx]) {
			continue;
		}

		taken[_x][_y] = true;
		isPossible |= solve(board, word, _x, _y, idx + 1);
		taken[_x][_y] = false;

	}

	return isPossible;

}

bool exist(vector<vector<char>>& board, string word) {
	n = board.size();
	m = board[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			taken[i][j] = true;
			if (board[i][j] == word[0] && solve(board, word, i, j, 1)) {
				return true;
			}
			taken[i][j] = false;
		}
	}

	return false;
}

int main() {
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "ABCCED";
	// string word = "SEE";
	// string word = "ABCB";

	// vector<vector<char>> board = {{'a'}};
	// string word = "a";

	cout << exist(board, word);
}