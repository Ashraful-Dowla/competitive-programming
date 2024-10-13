//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2014/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

bool resolve(vector<ll>&a, ll sum) {

	int n = a.size(), m = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] * 2 * n < sum) {
			m++;
		}
	}

	return 2 * m > n;
}

void solve() {

	int n;
	cin >> n;

	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if (n <= 2) {
		cout << -1 << endl;
		return ;
	}

	ll lo = 0, hi = 1e15, ans = -1;
	while (lo <= hi) {
		ll mid = (hi + lo) / 2;

		if (resolve(a, sum + mid)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
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