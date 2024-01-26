/*
https://atcoder.jp/contests/abc296/tasks/abc296_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	char ch[8][8];

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (ch[i][j] == '*') {
				cout << char(j + 'a') << 8 - i << endl;
				return 0;
			}
		}
	}
}