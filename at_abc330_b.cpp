/*
https://atcoder.jp/contests/abc330/tasks/abc330_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, l, r;
	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (x < l) {
			cout << l << " ";
		}
		else if (x > r) {
			cout << r << " ";
		}
		else {
			cout << x << " ";
		}
	}
	cout << endl;
}