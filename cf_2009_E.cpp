//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2009/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

pair<ll, ll> calc(ll k, ll mid, ll n) {

	ll left = (mid * (2 * k - 1 + mid)) / 2;
	ll right = (n * (2 * k - 1 + n)) / 2 - left;

	return {left, right};
}

void solve() {

	ll n, k;
	cin >> n >> k;

	ll lo = 1, hi = n, curr = 1;

	while (lo <= hi) {

		ll mid = (hi + lo) / 2;

		auto res = calc(k, mid, n);

		ll left = res.first, right = res.second;

		if (left < right) {
			curr = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	auto res1 = calc(k, curr, n);
	auto res2 = calc(k, curr + 1, n);

	cout << min(abs(res1.first - res1.second),
	            abs(res2.first - res2.second)) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}