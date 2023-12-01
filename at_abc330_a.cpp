/*
https://atcoder.jp/contests/abc330/tasks/abc330_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, p, ans = 0;

	cin >> n >> p;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (x >= p) {
			ans++;
		}
	}

	cout << ans << endl;
}