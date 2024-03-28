/*
https://www.spoj.com/problems/ANARC05B/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll dp[10005][2];

ll solve(vl &a, vl &b, int i, int t) {

	if (i >= a.size() && t == 0) {
		return 0;
	}
	if (i >= b.size() && t == 1) {
		return 0;
	}
	if (dp[i][t] != -1) {
		return dp[i][t];
	}

	ll ans = -1e6;
	if (t == 0) {
		ans = max(ans, solve(a, b, i + 1, t) + a[i]);

		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (idx < b.size() && b[idx] == a[i]) {
			ans = max(ans, solve(a, b, idx + 1, 1) + a[i]);
		}
	}
	else {
		ans = max(ans, solve(a, b, i + 1, t) + b[i]);

		int idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		if (idx < a.size() && a[idx] == b[i]) {
			ans = max(ans, solve(a, b, idx + 1, 0) + b[i]);
		}
	}

	return dp[i][t] = ans;
}

int main() {

	while (true) {

		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		vl a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int m;
		cin >> m;

		vl b(m);
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}

		for (int i = 0; i <= max(n, m); ++i) {
			dp[i][0] = dp[i][1] = -1;
		}

		ll ans = solve(a, b, 0, 0);
		ans = max(ans, solve(a, b, 0, 1));

		cout << ans << endl;
	}
}