/*
https://atcoder.jp/contests/abc318/tasks/abc318_b
*/
#include <bits/stdc++.h>
using namespace std;

bool arr[105][105];

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int i = a; i < b; ++i) {
			for (int j = c; j < d; ++j) {
				arr[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (arr[i][j]) ans++;
		}
	}

	cout << ans << endl;
}