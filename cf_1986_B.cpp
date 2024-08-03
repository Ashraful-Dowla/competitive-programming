//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1986/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n, m;
bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
vector<pair<int, int>> directions = {
	{0, -1},
	{0, 1},
	{1, 0},
	{ -1, 0}
};

void solve() {

	cin >> n >> m;

	int a[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			int mx = 0;
			for (auto d : directions) {
				int x = i + d.first;
				int y = j + d.second;

				if (!isValid(x, y)) continue;

				mx = max(mx, a[x][y]);
			}

			a[i][j] = min(a[i][j], mx);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}