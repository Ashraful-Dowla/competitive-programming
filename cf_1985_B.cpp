//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	int ans = 2;
	ll mx_sum = 0;
	for (int x = 2; x <= n; ++x) {
		ll sum = 0;
		for (int k = 1; k <= n; ++k) {
			if (k * x > n) {
				break;
			}
			sum += k * 1LL * x;
		}
		if (mx_sum <= sum) {
			ans = max(ans, x);
			mx_sum = sum;
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