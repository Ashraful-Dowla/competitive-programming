/*
https://atcoder.jp/contests/abc334/tasks/abc334_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 10;
const ll M = 998244353;

char ch[N][N];
bool vis[N][N];
int n, m, parent[N][N];

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j, int root) {

	vis[i][j] = true;

	parent[i][j] = root;

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || vis[x][y] || ch[x][y] == '.') {
			continue;
		}

		dfs(x, y, root);
	}
}

ll binaryExp(ll a, ll b) {

	ll res = 1;

	while (b) {
		if (b & 1) {
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return res;
}

int main() {

	cin >> n >> m;

	int dots = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] == '.') {
				dots++;
			}
		}
	}

	int c = 0, k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && ch[i][j] == '#') {
				dfs(i, j, ++k);
				c++;
			}
		}
	}

	ll exp = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '.') {

				set<int> s;
				for (auto d : directions) {
					int x = i + d.first;
					int y = j + d.second;

					if (!isValid(x, y) || ch[x][y] == '.') {
						continue;
					}

					s.insert(parent[x][y]);
				}

				exp = (exp + c - s.size() + 1) % M;
			}
		}
	}

	ll ans = binaryExp(dots, M - 2);
	ans = (ans * exp) % M;

	cout << ans << endl;
}