/*
https://atcoder.jp/contests/abc369/tasks/abc369_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
ll a[N], dp[N][2];
int n;

ll solve(int i, int t) {

	if (i == n) {
		return 0;
	}
	if (dp[i][t] != -1) {
		return dp[i][t];
	}

	ll ans = 0;
	if (t == 0) {
		ans = max(ans, solve(i + 1, t ^ 1) + 2 * a[i]);
	}
	else {
		ans = max(ans, solve(i + 1, t ^ 1) + a[i]);
	}

	ans = max(ans, solve(i + 1, t));

	return dp[i][t] = ans;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i][0] = dp[i][1] = -1;
	}

	cout << solve(0, 1) << endl;
}