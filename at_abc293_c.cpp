/*
https://atcoder.jp/contests/abc293/tasks/abc293_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 15;
int a[N][N], n, m;
unordered_map<int, bool> mp;

vector<pair<int, int>> directions = {
	{0, 1},
	{1, 0}
};

bool isValid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

ll dfs(int i, int j) {

	if (i == n && j == m) {
		return 1;
	}

	ll cnt = 0;
	for (auto d : directions) {
		int x = i + d.first;
		int y = j + d.second;

		if (!isValid(x, y) || mp[a[x][y]]) {
			continue;
		}

		mp[a[x][y]] = true;
		cnt += dfs(x, y);
		mp[a[x][y]] = false;
	}

	return cnt;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	mp[a[1][1]] = true;
	cout << dfs(1, 1) << endl;
}