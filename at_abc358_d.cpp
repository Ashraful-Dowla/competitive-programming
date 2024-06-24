/*
https://atcoder.jp/contests/abc358/tasks/abc358_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, m;
	cin >> n >> m;

	vector<ll> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int l = 0, r = 0;

	ll ans = 0;
	while (l < n && r < m) {
		if (a[l] >= b[r]) {
			ans += a[l];
			l++, r++;
		}
		else {
			l++;
		}
	}

	cout << (r == m ? ans : -1) << endl;
}