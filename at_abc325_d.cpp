/*
https://atcoder.jp/contests/abc325/tasks/abc325_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool cmp(pll a, pll b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	vector<pll> v(n);

	for (int i = 0; i < n; ++i) {
		ll t, d;
		cin >> t >> d;

		v[i] = {t, t + d};
	}

	sort(v.begin(), v.end(), cmp);

	set<ll> s, t;
	for (int i = 0; i < n; ++i) {
		s.insert(v[i].first);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {

		if (s.lower_bound(v[i].first) == s.end()) {
			continue;
		}

		while (t.find(*s.lower_bound(v[i].first)) != t.end()) {
			s.erase(*s.lower_bound(v[i].first));
		}

		if (s.lower_bound(v[i].first) == s.end()) {
			continue;
		}

		ll k = *s.lower_bound(v[i].first);

		if (k > v[i].second) {
			continue;
		}

		ans++;

		s.erase(k);
		s.insert(k + 1);
		t.insert(k);
	}

	cout << ans << endl;
}