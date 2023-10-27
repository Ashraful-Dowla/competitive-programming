/*
https://atcoder.jp/contests/abc325/tasks/abc325_c
*/
#include <bits/stdc++.h>
using namespace std;

char ch[1005][1005];
bool visited[1005][1005];
int n, m;

vector<pair<int, int>> directions = {
	{ -1, 0},
	{1, 0},
	{0, 1},
	{0, -1},
	{ -1, -1},
	{ -1, 1},
	{1, 1},
	{1, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j) {

	visited[i][j] = true;

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || visited[x][y] || ch[x][y] != '#')
			continue;

		dfs(x, y);
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && ch[i][j] == '#') {
				ans++;
				dfs(i, j);
			}
		}
	}

	cout << ans << endl;
}