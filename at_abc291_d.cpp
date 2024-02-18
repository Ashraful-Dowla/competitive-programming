/*
https://atcoder.jp/contests/abc291/tasks/abc291_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const ll M = 998244353;

ll a[N], b[N];
ll dp[N][2];

ll solve(int i, int flip) {

	if (i < 0) return 1;
	if (dp[i][flip] != -1) return dp[i][flip];

	ll ans = 0;
	if (flip) {
		if (a[i] != b[i + 1]) {
			ans = (ans + solve(i - 1, !flip)) % M;
		}
		if (b[i] != b[i + 1]) {
			ans = (ans + solve(i - 1, flip)) % M;
		}
	}
	else {
		if (a[i] != a[i + 1]) {
			ans = (ans + solve(i - 1, flip)) % M;
		}
		if (b[i] != a[i + 1]) {
			ans = (ans + solve(i - 1, !flip)) % M;
		}
	}

	return dp[i][flip] = ans;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		dp[i][0] = dp[i][1] = -1;
	}

	cout << (solve(n - 2, 0) + solve(n - 2, 1)) % M << endl;
}