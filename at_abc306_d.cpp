/*
https://atcoder.jp/contests/abc306/tasks/abc306_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

ll x[N], y[N], dp[N][2];
int n;

ll solve(int i, int t) {

	if (i == n) {
		return 0;
	}
	if (dp[i][t] != -1) {
		return dp[i][t];
	}

	ll ans = 0;
	if (x[i] == 1) {
		if (!t) {
			ans = max(ans, solve(i + 1, 1) + y[i]);
		}
	}
	else {
		ans = max(ans, solve(i + 1, 0) + y[i]);
	}

	ans = max(ans, solve(i + 1, t));

	return dp[i][t] = ans;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][1] = -1;
	}

	cout << solve(0, 0) << endl;
}