/*
https://atcoder.jp/contests/abc339/tasks/abc339_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 62;

char ch[N][N];
bool vis[N][N][N][N];
int n;

struct node
{
	int x1, y1, x2, y2;
	ll dis;
};

vector<pii> directions = {
	{1, 0},
	{ -1, 0},
	{0, 1},
	{0, -1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

ll bfs(int x1, int y1, int x2, int y2) {

	vis[x1][y1][x2][y2] = true;
	queue<node> q;
	q.push({x1, y1, x2, y2, 0});

	ll ans = -1;
	while (!q.empty()) {
		node p = q.front();
		q.pop();

		x1 = p.x1, y1 = p.y1;
		x2 = p.x2, y2 = p.y2;

		if (x1 == x2 && y1 == y2) {
			ans = p.dis;
			break;
		}

		for (auto d : directions) {
			x1 = p.x1, y1 = p.y1;
			x2 = p.x2, y2 = p.y2;

			if (isValid(x1 + d.first, y1 + d.second) && ch[x1 + d.first][y1 + d.second] != '#') {
				x1 += d.first;
				y1 += d.second;
			}
			if (isValid(x2 + d.first, y2 + d.second) && ch[x2 + d.first][y2 + d.second] != '#') {
				x2 += d.first;
				y2 += d.second;
			}
			if (!vis[x1][y1][x2][y2]) {
				q.push({x1, y1, x2, y2, p.dis + 1});
				vis[x1][y1][x2][y2] = true;
			}
		}
	}

	return ans;

}

int main() {

	cin >> n;

	int x1 = -1, y1, x2 = -1, y2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == 'P') {
				if (x1 == -1) {
					x1 = i, y1 = j;
				}
				else  {
					x2 = i, y2 = j;
				}
			}
		}
	}

	cout << bfs(x1, y1, x2, y2) << endl;
}