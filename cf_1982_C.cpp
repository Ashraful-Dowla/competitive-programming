//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1982/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	ll l, r;
	cin >> n >> l >> r;

	vector<ll> v(n);
	queue<int> q;


	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll curr = 0, ans = 0;

	int i = 0, j = 0;
	while (i < n) {

		while (j < n && curr < l) {
			curr += v[j];
			j++;
		}

		if (l <= curr && curr <= r) {
			ans++;
			i = j;
			curr = 0;
		}
		else {
			curr -= v[i];
			i++;
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