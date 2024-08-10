//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1993/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	multiset<ll> even, odd;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;

		if (x % 2 == 0) {
			even.insert(x);
		}
		else {
			odd.insert(x);
		}
	}

	if (even.size() == 0 || odd.size() == 0) {
		cout << 0 << endl;
		return ;
	}

	int ans = even.size();
	ll mx = *(--odd.end());

	for (ll x : even) {
		if (x < mx) {
			mx += x;
		}
		else {
			ans++;
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