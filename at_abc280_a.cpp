/*
https://atcoder.jp/contests/abc280/tasks/abc280_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;

			if (ch == '#') {
				ans++;
			}
		}
	}

	cout << ans << endl;
}