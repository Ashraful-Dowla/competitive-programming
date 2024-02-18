#include <bits/stdc++.h>
using namespace std;


int main() {

	int n, m, t;
	string s;
	char ch[505][505];

	cin >> n >> m >> t;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == '.') {
				int x = i, y = j;
				bool ok = true;

				for (int k = 0; k < t; ++k) {

					if (s[k] == 'L') y--;
					else if (s[k] == 'R') y++;
					else if (s[k] == 'U') x--;
					else x++;

					if (ch[x][y] == '#') {
						ok = false;
						break;
					}
				}

				if (ok) ans++;
			}
		}
	}

	cout << ans << endl;
}