/*
https://atcoder.jp/contests/abc302/tasks/abc302_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, st, nd;
char ch[105][105];
bool vis[105][105];
vector<pii> res;
vector<vector<pii>> sol;
string s = "snuke";
map<vector<pii>, bool> mp;

vector<pair<int, int>> directions = {
	{1, 0},
	{ -1, 0},
	{0, 1},
	{0, -1},
	{ -1, -1},
	{1, -1},
	{1, 1},
	{ -1, 1}
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j, int k) {

	if (k == 5) {
		vector<pii> ans = res;
		ans.insert(ans.begin(), {st, nd});

		if (!mp[ans]) {
			sol.push_back(ans);
			mp[ans] = true;
		}
		return ;
	}

	vis[i][j] = true;

	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || vis[x][y] || ch[x][y] != s[k]) {
			continue;
		}

		res.push_back({x, y});
		dfs(x, y, k + 1);
		res.pop_back();
		vis[i][j] = false;
	}
}

bool check(vector<pii>& ans) {

	set<int> row, col;
	for (int i = 0; i < 5; ++i) {
		row.insert(ans[i].first);
		col.insert(ans[i].second);
	}

	set<double> gradient;
	for (int i = 1; i < 5; ++i) {
		double dx = ans[i - 1].first - ans[i].first;
		double dy = ans[i - 1].second - ans[i].second;

		gradient.insert(dy / dx);
	}

	return row.size() == 1 | col.size() == 1 | gradient.size() == 1;
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

			if (ch[i][j] == 's' && !vis[i][j]) {
				st = i, nd = j;
				dfs(i, j, 1);
				vis[i][j] = false;
			}
		}
	}


	for (auto v : sol) {
		if (check(v)) {
			for (auto p : v) {
				cout << p.first + 1 << " " << p.second + 1 << endl;
			}
			return 0;
		}
	}
}