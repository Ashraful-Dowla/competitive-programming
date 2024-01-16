/*
https://atcoder.jp/contests/abc336/tasks/abc336_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 1), l(n + 2, 0), r(n + 2, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; ++i) {
		l[i] = min(v[i], l[i - 1] + 1);
	}

	for (int i = n; i >= 1; --i) {
		r[i] = min(v[i], r[i + 1] + 1);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, min(l[i], r[i]));
	}

	cout << ans << endl;
}