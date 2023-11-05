/*
https://atcoder.jp/contests/abc321/tasks/abc321_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, m, p;
	cin >> n >> m >> p;

	vector<ll> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	ll pf[m + 1] = {0};

	sort(b.begin(), b.end());

	for (int i = 1; i <= m; ++i) {
		pf[i] = pf[i - 1] + b[i - 1];
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i) {

		ll d = p - a[i];

		if (d > 0) {

			auto it = upper_bound(b.begin(), b.end(), d);

			if (it == b.end()) {
				sum += a[i] * m + pf[m];
			}
			else {
				int idx = it - b.begin();
				sum += a[i] * idx + pf[idx];
				sum += p * 1LL * (m - idx);
			}

		}
		else {
			sum += p * 1LL * m;
		}
	}

	cout << sum << endl;
}