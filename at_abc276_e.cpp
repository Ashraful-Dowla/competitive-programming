/*
https://atcoder.jp/contests/abc276/tasks/abc276_e
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> ch;
vector<vector<bool>> vis;

vector<pair<int, int>> directions = {
	{1, 0},
	{ -1, 0},
	{0, 1},
	{0, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int i, int j, int k) {

	vis[i][j] = true;

	bool isPossible = false;
	for (auto d : directions) {

		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || ch[x][y] == '#') {
			continue;
		}

		if (vis[x][y]) {
			if (ch[x][y] == 'S' && k + 1 >= 4) {
				return true;
			}
			continue;
		}

		isPossible |= dfs(x, y, k + 1);
	}

	return isPossible;
}

int main() {

	cin >> n >> m;

	ch.assign(n, vector<char>(m));
	vis.assign(n, vector<bool>(m, false));

	int x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] == 'S') {
				x = i, y = j;
			}
		}
	}

	cout << (dfs(x, y, 0) ? "Yes" : "No") << endl;
}