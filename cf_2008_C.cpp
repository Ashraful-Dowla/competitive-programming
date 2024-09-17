//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/2008/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

ll calc(ll n) {
	return n * (n - 1);
}

void solve() {

	ll l, r;
	cin >> l >> r;

	ll d = r - l;

	ll lo = 1, hi = 1e6;

	ll ans = 1;
	while (lo <= hi) {

		ll mid = (hi + lo) / 2;

		ll res = calc(mid);

		if (res <= 2 * d) {
			ans = max(ans, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
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