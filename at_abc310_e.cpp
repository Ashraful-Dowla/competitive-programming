/*
https://atcoder.jp/contests/abc310/tasks/abc310_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
ll dp[N][2];

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	s = '_' + s;

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') {
			dp[i][0] = 1;
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		}
		else {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0] + 1;
		}

		ans += dp[i][1];
	}

	cout << ans << endl;
}