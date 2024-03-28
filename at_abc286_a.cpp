/*
https://atcoder.jp/contests/abc286/tasks/abc286_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = p, j = r; i <= q, j <= s; ++i, ++j) {
		swap(a[i], a[j]);
	}

	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}