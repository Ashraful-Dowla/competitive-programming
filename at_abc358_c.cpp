/*
https://atcoder.jp/contests/abc358/tasks/abc358_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;
			if (ch == 'o') {
				v[i] |= (1 << j);
			}
		}
	}

	int ans = n;
	for (int mask = 1; mask < (1 << n); ++mask) {
		int res = 0;
		for (int j = 0; j < n; ++j) {
			if (mask & (1 << j)) {
				res |= v[j];
			}
		}

		if (__builtin_popcount(res) == m) {
			ans = min(ans, __builtin_popcount(mask));
		}
	}

	cout << ans << endl;
}