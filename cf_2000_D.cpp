//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2000/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	int n;
	cin >> n;

	vector<ll> pf(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		pf[i] = pf[i - 1] + x;
	}

	string s;
	cin >> s;

	s = "_" + s;

	int l = 1, r = n;
	
	ll ans = 0;
	while (l < r) {

		while (l < n && s[l] != 'L') {
			l++;
		}

		while (r > 1 && s[r] != 'R') {
			r--;
		}

		if (l < r) {
			ans += pf[r] - pf[l - 1];
			l++, r--;
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