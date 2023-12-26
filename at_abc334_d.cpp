/*
https://atcoder.jp/contests/abc334/tasks/abc334_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, q;
	cin >> n >> q;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<ll> d;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
		d.push_back(sum);
	}

	while (q--) {
		ll x;
		cin >> x;

		auto it = lower_bound(d.begin(), d.end(), x);

		if (it == d.end()) {
			cout << n << endl;
		}
		else {
			int idx = it - d.begin() + 1;

			if (*it > x) {
				idx--;
			}
			cout << idx << endl;
		}
	}
}