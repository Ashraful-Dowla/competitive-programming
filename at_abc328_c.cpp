/*
https://atcoder.jp/contests/abc328/tasks/abc328_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	char s[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	vector<int> a(n + 1, 0), pf(n + 1, 0);

	for (int i = 1; i + 1 <= n; ++i) {
		if (s[i] == s[i + 1])
			a[i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + a[i];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pf[r - 1] - pf[l - 1] << endl;
	}
}