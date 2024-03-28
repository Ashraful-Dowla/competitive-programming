/*
https://www.spoj.com/problems/ALTSEQ/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[5005], n, dp[5005];

ll solve(int i) {

	if (i == n) {
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}

	ll ans = 0;
	for (int j = i + 1; j < n; ++j) {
		if (a[i] > 0 && a[j] < 0 &&  a[i] < abs(a[j])) {
			ans = max(ans, solve(j) + 1);
		}
		if (a[i] < 0 && a[j] > 0 && abs(a[i]) < a[j]) {
			ans = max(ans, solve(j) + 1);
		}
	}

	return dp[i] = ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i] = -1;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, solve(i) + 1);
	}

	cout << ans << endl;
}