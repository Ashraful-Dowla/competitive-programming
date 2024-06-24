//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	ll x, y, z, k;
	cin >> x >> y >> z >> k;

	ll ans = 0;
	for (ll i = 1; i <= x; ++i) {
		for (ll j = 1; j <= y; ++j) {
			if (k % (i * j) == 0) {
				ll p = k / (i * j);
				if (i <= x && j <= y && p <= z) {
					ll res = (x - i + 1) * (y - j + 1) * (z - p + 1);
					ans = max(ans, res);
				}
			}
		}
	}

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