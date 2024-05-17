/*
https://atcoder.jp/contests/abc282/tasks/abc282_b
*/
#include <bits/stdc++.h>
using namespace std;

bool check(int m, string s, string t) {
	for (int i = 0; i < m; ++i) {
		if (s[i] == 'x' && s[i] == t[i]) {
			return false;
		}
	}
	return true;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans += check(m, v[i], v[j]);
		}
	}

	cout << ans << endl;
}