/*
https://atcoder.jp/contests/abc348/tasks/abc348_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int N = 400;
const int INF = 1e7;

int n, m, sx, sy, tx, ty, r[N], c[N], e[N];
char ch[N][N];
bool isReachable[N][N];

vector<pii> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vvi bfs(int x, int y) {

	vvi dis(n, vi(m, INF));

	if (ch[x][y] == '#') {
		return dis;
	}

	queue<pii> q;
	q.push({x, y});
	dis[x][y] = 0;

	while (!q.empty()) {

		int dx = q.front().first;
		int dy = q.front().second;

		q.pop();

		for (auto d : directions) {
			int xx = dx + d.first;
			int yy = dy + d.second;

			if (!isValid(xx, yy) || ch[xx][yy] == '#') {
				continue;
			}

			if (dis[xx][yy] > dis[x][y] + 1) {
				dis[xx][yy] = dis[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}

	return dis;
}

vector<bool> bfs2(int s, int qq) {

	vector<bool> vis(qq, false);

	queue<int> q;
	q.push(s);
	vis[s] = true;

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int j = 0; j < qq; ++j) {
			if (isReachable[f][j] && !vis[j]) {
				vis[j] = true;
				q.push(j);
			}
		}
	}

	return vis;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (ch[i][j] == 'T') {
				tx = i;
				ty = j;
			}
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> r[i] >> c[i] >> e[i];
		--r[i], --c[i];
	}

	r[q] = sx, c[q] = sy;
	r[q + 1] = tx, c[q + 1] = ty;

	q += 2;

	for (int i = 0; i < q; ++i) {
		auto dis = bfs(r[i], c[i]);
		for (int j = 0; j < q; ++j) {
			if (dis[r[j]][c[j]] <= e[i]) {
				isReachable[i][j] = true;
			}
		}
	}

	auto res = bfs2(q - 2, q);

	cout << (res[q - 1] ? "Yes" : "No") << endl;
}