//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1982/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	ll x, y, k;
	cin >> x >> y >> k;

	while (k > 0 && x != 1) {

		ll d = ((x + y - 1) / y) * y - x;
		d = min(max(1LL, d), k);
		x += d;

		while (x % y == 0) {
			x /= y;
		}

		k -= d;
	}

	cout << x + k % (y - 1) << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}