/*
https://cses.fi/problemset/task/1084/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, m;
	ll k;

	cin >> n >> m >> k;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	multiset<ll> ms;

	for (int i = 0; i < m; ++i) {
		ll x;
		cin >> x;
		ms.insert(x);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; ++i) {

		auto it = ms.lower_bound(v[i] - k);

		if (it != ms.end() && abs(*it - v[i]) <= k) {
			ans++;
			ms.erase(it);
			continue;
		}

		it = ms.lower_bound(v[i] + k);

		if (it != ms.end() && abs(*it - v[i]) <= k) {
			ans++;
			ms.erase(it);
		}
	}

	cout << ans << endl;
}