//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1986/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	int n;
	ll k;
	cin >> n >> k;

	map<ll, vector<ll>> mp;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;

		mp[x % k].push_back(x / k);
	}

	ll ans = 0;
	int odd = 0;
	for (auto p : mp) {
		int idx = p.first;

		vector<ll> &v = mp[p.first];

		int sz = v.size();
		sort(v.begin(), v.end());
		odd += (sz % 2);

		if (odd > 1) {
			cout << -1 << endl;
			return ;
		}
		if (sz == 1) {
			continue;
		}

		if (sz % 2 == 0) {
			for (int i = 0; i < sz; i += 2) {
				ans += v[i + 1] - v[i];
			}
		}
		else {
			vector<ll> pf(sz, 0), sf(sz, 0);

			pf[1] = v[1] - v[0];
			for (int i = 3; i < sz; i += 2) {
				pf[i] = pf[i - 2] + v[i] - v[i - 1];
			}

			sf[sz - 2] = v[sz - 1] - v[sz - 2];
			for (int i = sz - 4; i >= 0; i -= 2) {
				sf[i] = sf[i + 2] + v[i + 1] - v[i];
			}

			ll mn = 1e18;
			for (int i = 0; i < sz; i += 2) {
				ll sum = 0;
				if (i - 1 > 0) sum += pf[i - 1];
				if (i + 1 < sz) sum += sf[i + 1];
				mn = min(mn, sum);
			}

			ans += mn;
		}
	}

	if (n % 2 == 0 && odd == 0) {
		cout << ans << endl;
	}
	else if (n % 2 == 1 && odd == 1) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}