/*
https://atcoder.jp/contests/abc302/tasks/abc302_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, m;
	cin >> n >> m;

	ll d;
	cin >> d;

	vector<ll> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = -1;
	for (int i = 0; i < n; ++i) {

		auto it = lower_bound(b.begin(), b.end(), a[i]);

		int st = -1;
		if (it == b.end()) {
			st = n - 1;
		}
		else {
			st = it - b.begin();
		}

		it = lower_bound(b.begin(), b.end(), a[i] + d);
		int nd = -1;

		if (it == b.end()) {
			nd = n - 1;
		}
		else {

			nd = it - b.begin();

			if (b[nd] - a[i] > d) {
				nd--;
			}
		}

		if (abs(b[st] - a[i]) <= d) {
			ans = max(ans, b[st] + a[i]);
		}
		if (abs(b[nd] - a[i]) <= d) {
			ans = max(ans, b[nd] + a[i]);
		}

	}

	for (int i = 0; i < m; ++i) {

		auto it = lower_bound(a.begin(), a.end(), b[i]);

		int st = -1;
		if (it == a.end()) {
			st = n - 1;
		}
		else {
			st = it - a.begin();
		}

		it = lower_bound(a.begin(), a.end(), b[i] + d);
		int nd = -1;

		if (it == a.end()) {
			nd = n - 1;
		}
		else {

			nd = it - a.begin();

			if (a[nd] - b[i] > d) {
				nd--;
			}
		}

		if (abs(a[st] - b[i]) <= d) {
			ans = max(ans, a[st] + b[i]);
		}
		if (abs(a[nd] - b[i]) <= d) {
			ans = max(ans, a[nd] + b[i]);
		}

	}

	cout << ans << endl;
}