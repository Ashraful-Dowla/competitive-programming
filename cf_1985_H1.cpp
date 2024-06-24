//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/H1
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 2e6 + 10;
int par[N], sz[N], ans;

vector<vector<int>> mark;
vector<vector<char>> ch;
vector<vector<bool>> vis;

vector<pair<int, int>> directions = {
	{0, 1},
	{0, -1},
	{1, 0},
	{ -1, 0}
};

void make(int n) {
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		par[b] = a;
		sz[a] += sz[b];
	}
}

bool isValid(int n, int m, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int n, int m, int i, int j) {

	vis[i][j] = true;

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(n, m, x, y) || ch[x][y] == '.' || vis[x][y]) {
			continue;
		}

		Union(mark[i][j], mark[x][y]);
		dfs(n, m, x, y);
	}
}

void solve() {

	int n, m;
	cin >> n >> m;

	int cnt = 0;

	ch.assign(n, vector<char>(m));
	mark.assign(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
			mark[i][j] = ++cnt;
		}
	}

	make(n * m);

	ans = 0;
	vis.assign(n, vector<bool>(m, false));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '.' || vis[i][j]) continue;
			dfs(n, m, i, j);
			ans = max(ans, sz[find(mark[i][j])]);
		}
	}

	for (int i = 0; i < n; ++i) {
		int res = 0;
		set<int> s;
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '.') {
				res++;
				for (auto d : directions) {
					int x = i + d.first;
					int y = j + d.second;

					if (!isValid(n, m, x, y) || ch[x][y] == '.') {
						continue;
					}

					int root = find(mark[x][y]);

					if (s.find(root) == s.end()) {
						res += sz[root];
						s.insert(root);
					}
				}
			}
		}

		ans = max(ans, res);
	}

	for (int j = 0; j < m; ++j) {
		int res = 0;
		set<int> s;
		for (int i = 0; i < n; ++i) {
			if (ch[i][j] == '.') {
				res++;
				for (auto d : directions) {
					int x = i + d.first;
					int y = j + d.second;

					if (!isValid(n, m, x, y) || ch[x][y] == '.') {
						continue;
					}

					int root = find(mark[x][y]);

					if (s.find(root) == s.end()) {
						res += sz[root];
						s.insert(root);
					}
				}
			}
		}

		ans = max(ans, res);
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}