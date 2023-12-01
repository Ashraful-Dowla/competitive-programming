/*
https://atcoder.jp/contests/abc310/tasks/abc310_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, p, q;
	cin >> n >> p >> q;


	int ans = p;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ans = min(ans, x + q);
	}

	cout << ans << endl;
}