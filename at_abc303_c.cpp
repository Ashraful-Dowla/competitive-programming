/*
https://atcoder.jp/contests/abc303/tasks/abc303_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, h, k;
	cin >> n >> m >> h >> k;

	string s;
	cin >> s;

	map<pair<int, int>, bool> health;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		health[ {x, y}] = true;
	}

	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {

		if (s[i] == 'R') {
			x++;
		}
		else if (s[i] == 'L') {
			x--;
		}
		else if (s[i] == 'U') {
			y++;
		}
		else {
			y--;
		}

		h--;

		if (h < 0) {
			cout << "No" << endl;
			return 0;
		}
		else if (h < k && health[ {x, y}]) {
			h = k;
			health[ {x, y}] = false;
		}
	}

	cout << "Yes" << endl;
}