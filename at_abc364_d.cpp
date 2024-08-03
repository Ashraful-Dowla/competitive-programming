/*
https://atcoder.jp/contests/abc364/tasks/abc364_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll func(vector<ll> &v, ll x, ll b) {

	auto ub = upper_bound(v.begin(), v.end(), b + x);
	auto lb = lower_bound(v.begin(), v.end(), b - x);

	return ub - lb;
}

int main() {


	int n, q;
	cin >> n >> q;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	while (q--) {

		ll b, k;
		cin >> b >> k;

		ll lo = -1e9, hi = 1e9;

		while (hi - lo > 1) {
			ll mid = (lo + hi) / 2;
			if (func(v, mid, b) < k) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}

		cout << hi << endl;
	}


}