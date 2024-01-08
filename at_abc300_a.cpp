/*
https://atcoder.jp/contests/abc300/tasks/abc300_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, a, b;
	cin >> n >> a >> b;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;

		if (c == a + b) {
			ans = i + 1;
		}
	}

	cout << ans << endl;
}