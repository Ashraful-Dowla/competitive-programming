/*
https://www.spoj.com/problems/ALTSEQ/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[5005], n, dp[5005];

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > 0 && a[j] < 0 && a[i] < abs(a[j])) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
			if (a[i] < 0 && a[j] > 0 && abs(a[i]) < a[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}