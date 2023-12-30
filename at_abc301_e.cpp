#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

char ch[305][305];
int n, m, t;

vector<pii> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<vector<int>> bfs(int i, int j) {

	vector<vector<int>> res(n, vector<int>(m, INF));
	res[i][j] = 0;

	queue<pii> q;
	q.push({i, j});

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		int ii = p.first;
		int jj = p.second;

		for (auto d : directions) {
			int x = ii + d.first;
			int y = jj + d.second;

			if (!isValid(x, y) || ch[x][y] == '#') {
				continue;
			}

			if (res[x][y] > res[ii][jj] + 1) {
				res[x][y] = res[ii][jj] + 1;
				q.push({x, y});
			}
		}
	}

	return res;
}

int solve(int candies, int pos, int mask) {

}

int main() {

	cin >> n >> m >> t;

	int si, sj, gi, gj;

	vector<pii> candies;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == 's') {
				si = i, sj = j;
			}
			else if (ch[i][j] == 'g') {
				gi = i, gj = j;
			}
			else {
				candies.push_back({i, j});
			}
		}
	}


	vector<vector<vector<int>>> dis;

	for (auto p : candies) {
		int x = p.first;
		int y = p.second;
		dis.push_back(bfs(x, y));
	}

	for (int i = 0; i < candies.size(); ++i) {

	}
}