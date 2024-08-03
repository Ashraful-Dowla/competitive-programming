/*
https://atcoder.jp/contests/abc364/tasks/abc364_b
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, si, sj, xi, yi;
string s;
char ch[100][100];

bool isValid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

map<char, pair<int, int>> mp = {
	{'U', { -1, 0}},
	{'D', {1, 0}},
	{'L', {0, -1}},
	{'R', {0, 1}}
};

void dfs(int i, int j, int k) {

	if (k == s.size()) {
		xi = i, yi = j;
		return ;
	}

	auto p = mp[s[k]];

	int dx = i + p.first;
	int dy = j + p.second;

	if (isValid(dx, dy) && ch[dx][dy] == '.') {
		dfs(dx, dy, k + 1);
	}
	else {
		dfs(i, j, k + 1);
	}

}

int main() {

	cin >> n >> m;
	cin >> si >> sj;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch[i][j];
		}
	}

	cin >> s;

	xi = si, yi = sj;
	dfs(si, sj, 0);

	cout << xi << " " << yi << endl;
}