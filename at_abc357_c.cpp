/*
https://atcoder.jp/contests/abc357/tasks/abc357_c
*/
#include <bits/stdc++.h>
using namespace std;

char ch[7][1000][1000];

int main() {

	int n;
	cin >> n;

	ch[0][0][0] = '#';

	for (int i = 1; i <= n; ++i) {

		for (int j = 0; j < pow(3, i); j += pow(3, i - 1)) {
			for (int k = 0; k < pow(3, i); k += pow(3, i - 1)) {

				if (j == pow(3, i - 1) && k == j) {
					for (int a = 0; a < pow(3, i - 1); ++a) {
						for (int b = 0; b < pow(3, i - 1); ++b) {
							ch[i][a + j][b + k] = '.';
						}
					}
				}
				else {
					for (int a = 0; a < pow(3, i - 1); ++a) {
						for (int b = 0; b < pow(3, i - 1); ++b) {
							ch[i][a + j][b + k] = ch[i - 1][a][b];
						}
					}
				}

			}
		}
	}

	for (int j = 0; j < pow(3, n); ++j) {
		for (int k = 0; k < pow(3, n); ++k) {
			cout << ch[n][j][k];
		}
		cout << endl;
	}
}