//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/F
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	ll h;
	int n;
	cin >> h >> n;

	vector<ll> a(n), c(n);

	map<ll, vector<int>> g;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		g[1].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	ll hh = h;
	ll ans = 1;
	for (auto p : g) {

		ll t = p.first;
		ll power = 0;

		for (int i : g[t]) {
			power += a[i];
			g[t + c[i]].push_back(i);
		}

		hh -= power;

		if (hh <= 0) {
			ans = t;
			break;
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