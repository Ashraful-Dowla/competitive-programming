/*
https://atcoder.jp/contests/abc364/tasks/abc364_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll x, y;
	cin >> n >> x >> y;

	ll a[n + 1], b[n + 1];

	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}

	ll dp[n + 1][n + 1][x + 5];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= x; ++k) {
				dp[i][j][k] = 1e9;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int i = 1; i <= n; ++i) {

		for (int cnt = 0; cnt < n; ++cnt) {
			for (ll sum = 0; sum <= x; ++sum) {
				dp[i][cnt][sum] = dp[i - 1][cnt][sum];
			}
		}

		for (int cnt = 0; cnt < n; ++cnt) {
			for (ll sum = 0; sum + a[i] <= x; ++sum) {
				dp[i][cnt + 1][sum + a[i]] =
				    min(dp[i][cnt + 1][sum + a[i]], b[i] + dp[i - 1][cnt][sum]);
			}
		}
	}


	int ans = 1;
	for (int cnt = 0; cnt < n; ++cnt) {
		for (ll sum = 0; sum <= x; ++sum) {
			if (dp[n][cnt][sum] <= y) {
				ans = max(ans, cnt + 1);
			}
		}
	}

	cout << ans << endl;
}