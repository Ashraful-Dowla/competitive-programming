//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/G
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const ll mod = 1e9 + 7;

ll binaryExp(ll a, ll b) {

	ll res = 1;
	while (b) {
		if (b & 1LL) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}


void solve() {

	ll l, r, k;
	cin >> l >> r >> k;

	ll ans = (binaryExp(9 / k + 1, r) - binaryExp(9 / k + 1, l) + mod) % mod;
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