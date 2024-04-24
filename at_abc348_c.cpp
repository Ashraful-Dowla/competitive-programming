/*
https://atcoder.jp/contests/abc348/tasks/abc348_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n], c[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> c[i];
	}

	map<int, int> mp;

	for (int i = 0; i < n; ++i) {

		if (mp.find(c[i]) == mp.end()) {
			mp[c[i]] = a[i];
		}
		else {
			mp[c[i]] = min(mp[c[i]], a[i]);
		}
	}

	int ans = 0;
	for (auto p : mp) {
		ans = max(ans, p.second);
	}

	cout << ans << endl;
}