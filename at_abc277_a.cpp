/*
https://atcoder.jp/contests/abc277/tasks/abc277_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	int ans;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;

		if (p == x) {
			ans = i;
		}
	}

	cout << ans << endl;
}