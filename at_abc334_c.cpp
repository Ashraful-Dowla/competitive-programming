/*
https://atcoder.jp/contests/abc334/tasks/abc334_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, k;
	cin >> n >> k;

	vector<ll> v(k + 1), pf, sf;

	for (int i = 1; i <= k; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll ans = 1e10;
	if (k % 2 == 0) {

		ll res = 0;
		for (int i = 2; i <= k; i += 2) {
			res += v[i] - v[i - 1];
		}

		ans = min(ans, res);
	}
	else {

		pf.push_back(0);
		for (int i = 2; i < k; i += 2) {
			ll sum = pf.back() + v[i] - v[i - 1];
			pf.push_back(sum);
		}

		sf.push_back(0);
		for (int i = k; i > 1; i -= 2) {
			ll sum = sf.back() + v[i] - v[i - 1];
			sf.push_back(sum);
		}

		reverse(sf.begin(), sf.end());

		for (int i = 0; i < pf.size(); ++i) {
			ans = min(ans, pf[i] + sf[i]);
		}
	}

	cout << ans << endl;
}