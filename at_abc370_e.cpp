#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll binaryExp(ll a, ll b) {

	ll res = 1;
	while (b > 0) {
		if (b & 1LL) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}

	return res;
}

int main() {

	ll n, k;
	cin >> n >> k;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = binaryExp(2, n - 1);

	map<ll, int> mp;
	mp[0] = 0;

	ll res = 0, sum = 0;
	for (int i = 0; i < n; ++i) {

		sum += v[i];
		ll d = sum - k;

		if (mp.find(d) != mp.end()) {
			res = (res + mp[d]) % mod;
		}
		mp[d] += res;
	}

	cout << (mp[sum]) % mod << endl;
}