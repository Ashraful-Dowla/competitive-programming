/*
https://atcoder.jp/contests/abc318/tasks/abc318_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

ll arr[20][20], dp[20][N];
int n;

ll solve(int i, int taken) {

	if (i == n) {
		return 0;
	}

	if (dp[i][taken] != -1) {
		return dp[i][taken];
	}

	ll ans = 0;

	if (!(taken & (1 << i))) {
		for (int j = i + 1; j <= n; ++j) {
			if (!(taken & (1 << j))) {
				ans = max(ans, solve(i + 1, ((taken | (1 << i)) | (1 << j))) + arr[i][j]);
			}
		}
	}

	ans = max(ans, solve(i + 1, taken));

	return dp[i][taken] = ans;
}

int main() {

	cin >> n;

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = -1;
		}
	}

	cout << solve(1, 0) << endl;
}