/*
https://atcoder.jp/contests/abc367/tasks/abc367_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll m;
	cin >> n >> m;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<ll> pf = {0};
	for (int i = 0; i < 2 * n; ++i) {
		ll val = (pf.back() + v[i % n]) % m;
		pf.push_back(val);
	}

	map<ll, ll>mp;
	for (int i = 0; i < n; ++i) {
		mp[pf[i]]++;
	}

	ll ans = 0;
	for (int i = n; i < 2 * n; ++i) {
		mp[pf[i - n]]--;
		ans += mp[pf[i]];
		mp[pf[i]]++;
	}

	cout << ans << endl;
}