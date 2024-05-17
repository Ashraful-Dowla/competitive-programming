/*
https://atcoder.jp/contests/abc353/tasks/abc353_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 998244353;

ll binaryExp(ll a, ll b) {

	ll res = 1;
	while (b) {
		if ((b & 1LL)) {
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return res;
}

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = 0, m = 0, s = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = (ans + v[i] * m + s) % M;
		m = (m + binaryExp(10, log10(v[i]) + 1)) % M;
		s = (s + v[i]) % M;
	}

	cout << ans << endl;
}