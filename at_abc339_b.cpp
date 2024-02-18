/*
https://atcoder.jp/contests/abc339/tasks/abc339_b
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
	{ -1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int main() {

	int h, w, n;
	cin >> h >> w >> n;

	char ch[h][w];

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			ch[i][j] = '.';
		}
	}

	int i = 0, j = 0, d = 0;
	for (int k = 0; k < n; ++k) {

		if (ch[i][j] == '.') {
			ch[i][j] = '#';
			d = (d + 1) % 4;
		}
		else {
			ch[i][j] = '.';
			d = (d + 3) % 4;
		}

		i = (i + directions[d].first + h) % h;
		j = (j + directions[d].second + w) % w;
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << ch[i][j];
		}
		cout << endl;
	}
}