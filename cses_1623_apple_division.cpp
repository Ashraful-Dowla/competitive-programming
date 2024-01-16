/*
https://cses.fi/problemset/task/1623/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
const int M = 2e6;
int n;
vector<ll> v(N);
ll dp[N][M];

ll sum = 0;

ll solve(int i, int mask) {

	if (i == n) {
		ll sum1 = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i))) {
				sum1 += v[i];
			}
		}

		ll sum2 = sum - sum1;
		return abs(sum1 - sum2);
	}
	if (dp[i][mask] != -1) {
		return dp[i][mask];
	}

	ll ans = 1e18;
	ans = min(ans, solve(i + 1, mask | (1 << i)));
	ans = min(ans, solve(i + 1, mask));

	return dp[i][mask] = ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			dp[i][j] = -1;
		}
	}

	cout << solve(0, 0) << endl;
}