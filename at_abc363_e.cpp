/*
https://atcoder.jp/contests/abc363/tasks/abc363_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1005;
const int M = 1e5 + 10;

queue<pii> q[M];
int matrix[N][N];
bool vis[N][N];
int n, m, Y;

vector<pii> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {

	cin >> n >> m >> Y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				q[matrix[i][j]].push({i, j});
				vis[i][j] = true;
			}
		}
	}

	int ans = n * m;
	for (int i = 1; i <= Y; ++i) {
		while (!q[i].empty()) {
			ans--;
			auto p = q[i].front();
			q[i].pop();
			int x = p.first, y = p.second;

			for (auto d : directions) {
				int dx = x + d.first;
				int dy = y + d.second;

				if (!isValid(dx, dy) || vis[dx][dy]) {
					continue;
				}

				q[max(matrix[dx][dy], i)].push({dx, dy});
				vis[dx][dy] = true;
			}
		}
		cout << ans << endl;
	}

}