/*
https://cses.fi/problemset/task/1619/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	map<ll, ll> mp;

	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;

		mp[a]++;
		mp[b + 1]--;
	}

	ll prefix = 0, ans = 0;

	for (auto p : mp) {
		prefix += p.second;
		ans = max(ans, prefix);
	}

	cout << ans << endl;

}