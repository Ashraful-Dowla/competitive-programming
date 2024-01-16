/*
https://cses.fi/problemset/task/1624/
*/
#include <bits/stdc++.h>
using namespace std;

char ch[8][8];

bool isValid(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool check(int i, int j) {

	int x = i, y = j;
	while (isValid(x - 1, y - 1)) {
		if (ch[x - 1][y - 1] == '#')
			return false;
		x--, y--;
	}

	x = i, y = j;
	while (isValid(x - 1, y + 1)) {
		if (ch[x - 1][y + 1] == '#')
			return false;
		x--, y++;
	}

	x = i, y = j;
	while (isValid(x - 1, y)) {
		if (ch[x - 1][y] == '#')
			return false;
		x--;
	}

	return true;
}

int solve(int i) {

	if (i == 8) {
		return 1;
	}

	int cnt = 0;
	for (int j = 0; j < 8; ++j) {
		if (ch[i][j] == '.') {
			ch[i][j] = '#';
			if (check(i, j)) {
				cnt += solve(i + 1);
			}
			ch[i][j] = '.';
		}
	}

	return cnt;
}

int main() {

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> ch[i][j];
		}
	}

	cout << solve(0) << endl;
}