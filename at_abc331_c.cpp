/*
https://atcoder.jp/contests/abc331/tasks/abc331_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n), vp(n);

	vector<ll> pf(n + 1, 0);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		vp[i] = v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + v[i - 1];
	}

	vector<ll> ans(n, 0);
	for (int i = 0; i < n; ++i) {
		auto it = upper_bound(v.begin(), v.end(), vp[i]);

		if (it != v.end()) {
			int idx = it - v.begin();
			ans[i] = pf[n] - pf[idx];
		}
	}

	for (ll x : ans) {
		cout << x << " ";
	}
	cout << endl;

}