#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[20][20];
map<char, vector<pair<int, int>>>mp;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool solve(vector<vector<char>>& board, string &word, int x, int y, int idx) {

	if (idx == word.size()) return true;

	bool isPossible = false;
	for (auto d : directions) {
		int _x = x + d.first;
		int _y = y + d.second;

		if (!isValid(_x, _y) || visited[_x][_y] || board[_x][_y] != word[idx])
			continue;

		visited[_x][_y] = true;
		isPossible |= solve(board, word, _x, _y, idx + 1);
		visited[_x][_y] = false;
	}

	return isPossible;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	n = board.size();
	m = board[0].size();

	vector<string> ans;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mp[board[i][j]].push_back({i, j});
		}
	}

	for (string word : words) {

		if (word.size() > n * m) continue;

		auto coord = mp[word[0]];

		for (auto p : coord) {

			int i = p.first, j = p.second;
			visited[i][j] = true;
			bool ok = solve(board, word, i, j, 1);
			visited[i][j] = false;

			if (ok) {
				ans.push_back(word);
				break;
			}
		}
	}

	return ans;
}

int main() {

	vector<vector<char>> board = {
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};

	vector<string> words = {"oath", "pea", "eat", "rain"};

	// vector<vector<char>> board = {
	// 	{'a', 'b'},
	// 	{'c', 'd'},
	// };

	// vector<string> words = {"abcd"};

	// vector<vector<char>> board = {
	// 	{'o', 'a', 'b', 'n'},
	// 	{'o', 't', 'a', 'e'},
	// 	{'a', 'h', 'k', 'r'},
	// 	{'a', 'f', 'l', 'v'},
	// };

	// vector<string> words = {"oa", "oaa"};

	auto ans = findWords(board, words);

	for (string word : ans) {
		cout << word << " ";
	}
	cout << endl;
}