/*
https://atcoder.jp/contests/abc308/tasks/abc308_d
*/
#include <bits/stdc++.h>
using namespace std;

bool vis[505][505];
char ch[505][505];
int dp[505][505][5];

int n, m;
string s = "snuke";

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{ -1, 0},
	{1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, int idx) {

	if (s[idx] != ch[x][y]) return false;
	if (x + 1 == n && y + 1 == m) {
		return true;
	}
	if (dp[x][y][idx] != -1) {
		return dp[x][y][idx];
	}

	bool isPossible = false;
	for (auto d : directions) {

		int i = x + d.first;
		int j = y + d.second;

		if (!isValid(i, j) || vis[i][j]) {
			continue;
		}

		vis[i][j] = true;
		isPossible |= dfs(i, j, (idx + 1) % 5);
		vis[i][j] = false;
	}

	return dp[x][y][idx] = isPossible;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= 5; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	cout << (dfs(0, 0, 0) ? "Yes" : "No") << endl;
}