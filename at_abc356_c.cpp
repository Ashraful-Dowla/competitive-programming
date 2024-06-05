/*
https://atcoder.jp/contests/abc356/tasks/abc356_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a[m + 5];
	char r[m + 5];

	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;

		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}

		cin >> r[i];
	}

	int ans = 0;
	for (int msk = 0; msk < (1 << n); ++msk) {
		bool ok = true;
		for (int i = 0; i < m; ++i) {
			int ct = 0;
			for (int x : a[i]) {
				if (msk & (1 << (x - 1))) {
					ct++;
				}
			}
			if (r[i] == 'o' && ct < k) {
				ok = false;
			}
			if (r[i] == 'x' && ct >= k) {
				ok = false;
			}
		}
		if (ok) {
			ans++;
		}
	}

	cout << ans << endl;
}