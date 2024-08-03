/*
https://atcoder.jp/contests/abc275/tasks/abc275_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int mx = 0, ans;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (mx < x) {
			mx = x;
			ans = i + 1;
		}
	}

	cout << ans << endl;
}