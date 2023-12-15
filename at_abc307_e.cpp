/*
https://atcoder.jp/contests/abc307/tasks/abc307_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;
const int N = 1e6 + 10;

ll dp[N][2];

int main() {
	int n;
	ll m;

	cin >> n >> m;

	dp[1][1] = m;

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][0] * (m - 2) + dp[i - 1][1] * (m - 1)) % M;
		dp[i][1] = dp[i - 1][0] % M;
	}

	cout << dp[n][0] << endl;

}