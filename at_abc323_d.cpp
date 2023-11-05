/*
https://atcoder.jp/contests/abc323/tasks/abc323_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	unordered_map<ll, ll> mp;

	set<ll> s;
	for (int i = 0; i < n; ++i) {
		ll x, c;
		cin >> x >> c;

		s.insert(x);
		mp[x] = c;
	}

	while (s.size()) {

		ll x = *s.begin();
		s.erase(s.begin());

		ll val = mp[x] / 2;

		if (val > 0) {
			mp[2 * x] += val;
			mp[x] -= val * 2;

			s.insert(2 * x);
		}
	}

	ll ans = 0;
	for (auto x : mp) {
		ans += x.second;
	}

	cout << ans << endl;
}