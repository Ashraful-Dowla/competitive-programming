/*
https://atcoder.jp/contests/abc333/tasks/abc333_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e12;

ll pw(ll a, int b) {

	ll res = 1;
	for (int i = 0; i < b; ++i) {
		res *= a;
	}

	return res;
}

int main() {

	int n;
	cin >> n;

	vector<ll> v;
	unordered_map<ll, bool> mp;

	for (ll i = 1, ii = 1; i < N; ++ii) {
		// cout << i << endl;
		for (ll j = 1, jj = 1; j < N; ++jj) {
			// cout << j << endl;

			for (ll k = 1, kk = 1; k < N; ++kk) {
				// cout << k << endl;

				ll res = i + j + k;
				if (!mp[res]) {
					v.push_back(res);
					mp[res] = true;
				}
				k = k +	pw(10, kk);
			}
			j = j +	pw(10, jj);
		}
		i = i +	pw(10, ii);
	}

	sort(v.begin(), v.end());
	// cout << v.size() << endl;

	cout << v[n - 1] << endl;
}