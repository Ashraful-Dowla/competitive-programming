/*
https://atcoder.jp/contests/abc351/tasks/abc351_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, cntx, cnt, mark[N][N];
char ch[N][N];
bool vis[N][N];

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j, int c) {

	vis[i][j] = true;
	cnt++;

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || ch[x][y] == '#' || vis[x][y]) {
			continue;
		}

		if (ch[x][y] == 'x' && mark[x][y] != c) {
			cntx++;
			mark[x][y] = c;
			continue;
		}

		if (ch[x][y] == '.') {
			dfs(x, y, c);
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '#') {
				for (auto d : directions) {
					int x = i + d.first;
					int y = j + d.second;

					if (isValid(x, y) && ch[x][y] == '.') {
						ch[x][y] = 'x';
					}
				}
			}
		}
	}

	int ans = 1, c = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '.' && !vis[i][j]) {
				cntx = cnt = 0;
				dfs(i, j, c++);
				ans = max(ans, cnt + cntx);
			}
		}
	}

	cout << ans << endl;
}