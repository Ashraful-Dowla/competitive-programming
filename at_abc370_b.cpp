/*
https://atcoder.jp/contests/abc370/tasks/abc370_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n + 1][n + 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> a[i][j];
		}
	}

	int e = 1;

	for (int i = 1; i <= n; ++i) {
		if (e >= i) {
			e = a[e][i];
		}
		else {
			e = a[i][e];
		}
	}

	cout << e << endl;
}