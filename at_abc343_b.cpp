/*
https://atcoder.jp/contests/abc343/tasks/abc343_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) cout << j + 1 << " ";
		}
		cout << endl;
	}
}