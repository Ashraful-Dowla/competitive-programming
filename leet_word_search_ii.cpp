#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[20][20];
vector<string> ans;
unordered_map<string, bool> mp;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

struct node {
	bool endmark;
	node* next[27];
	string str;
	node() {
		endmark = false;
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
		}
	}
}* root;

void insert(string s) {
	node* curr = root;

	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
	}

	curr->endmark = true;
	curr->str = s;
}

void del(node* curr) {

	for (int i = 0; i < 26; ++i) {
		if (curr->next[i]) {
			del(curr->next[i]);
		}
	}

	delete(curr);
}

void dfs(vector<vector<char>>& board, int x, int y, node* curr) {

	if (curr->endmark) {
		if (!mp[curr->str]) {
			ans.push_back(curr->str);
			mp[curr->str] = true;
		}
	}

	for (auto d : directions) {
		int _x = x + d.first;
		int _y = y + d.second;

		if (!isValid(_x, _y) || visited[_x][_y]) continue;

		int idx = board[_x][_y] - 'a';
		if (curr->next[idx] == NULL) continue;

		visited[_x][_y] = true;
		dfs(board, _x, _y, curr->next[idx]);
		visited[_x][_y] = false;
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	n = board.size();
	m = board[0].size();

	root = new node();

	for (string word : words) {
		insert(word);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int idx = board[i][j] - 'a';
			if (root->next[idx]) {
				visited[i][j] = true;
				dfs(board, i, j, root->next[idx]);
				visited[i][j] = false;
			}
		}
	}

	del(root);
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