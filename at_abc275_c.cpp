/*
https://atcoder.jp/contests/abc275/tasks/abc275_c
*/
#include <bits/stdc++.h>
using namespace std;

char ch[10][10];

bool isValid(int x, int y) {
	return x >= 0 && x < 9 && y >= 0 && y < 9 && ch[x][y] == '#';
}

int main() {


	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> ch[i][j];
		}
	}

	set<set<pair<int, int>>> st;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (ch[i][j] == '#') {

				for (int dx = -8; dx < 9; ++dx) {
					for (int dy = -8; dy < 9; ++dy) {
						
						if (dx == 0 && dy == 0) continue;

						int i1 = i + dx, j1 = j + dy;
						int i2 = i1 - dy, j2 = j1 + dx;
						int i3 = i2 - dx, j3 = j2 - dy;

						if (isValid(i1, j1) && isValid(i2, j2) && isValid(i3, j3)) {

							set<pair<int, int>> s;

							s.insert({i, j});
							s.insert({i1, j1});
							s.insert({i2, j2});
							s.insert({i3, j3});

							st.insert(s);
						}
					}
				}
			}
		}
	}

	cout << st.size() << endl;
}