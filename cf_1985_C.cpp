//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll sum = 0, ans = 0;
	set<ll> s;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
		s.insert(v[i]);

		if (sum % 2 == 0 && s.find(sum / 2) != s.end()) {
			ans++;
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