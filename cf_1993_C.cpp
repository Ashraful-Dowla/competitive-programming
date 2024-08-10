//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1993/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


bool check(ll mx, ll x, ll k) {
	ll n = (mx - x) / k;
	return n % 2 == 0;
}

void solve() {

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	ll mx = a.back(), mn = a.back() + k - 1;
	for (int i = 0; i < n - 1; ++i) {
		ll l = a.back(), r = a.back() + k, ans;

		//on
		if (check(a.back(), a[i], k)) {
			while (l <= r) {
				ll mid = (l + r) / 2;

				if (check(mid, a[i], k)) {
					ans = mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}

			mn = min(mn, ans);
		}
		else {
			while (l <= r) {
				ll mid = (l + r) / 2;

				if (check(mid, a[i], k)) {
					ans = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			mx = max(mx, ans);
		}
	}

	cout << (mx <= mn ? mx : -1) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}