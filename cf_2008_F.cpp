/*
https://codeforces.com/problemset/problem/2008/F
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
const ll mod = 1e9 + 7;

ll binaryExp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1LL) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<ll> v(n);

	ll sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum1 = (sum1 + v[i]) % mod;
		sum2 = (sum2 + v[i] * v[i]) % mod;
	}

	ll P = (sum1 * sum1 % mod - sum2 + mod) % mod;
	ll Q = (n * 1LL * (n - 1)) % mod;

	ll invQ = binaryExp(Q, mod - 2);

	ll ans = (P * invQ) % mod;

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
