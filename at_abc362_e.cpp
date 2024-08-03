/*
https://atcoder.jp/contests/abc362/tasks/abc362_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

const int N = 100;
ll a[N], dp[N][N][N];
int n;

ll solve(int pi, int ci, int k) {

	if (k == 0) {
		return 1;
	}
	if (dp[pi][ci][k] != -1) {
		return dp[pi][ci][k];
	}

	ll d = a[ci] - a[pi], ans = 0;
	for (int j = ci + 1; j <= n; ++j) {
		if (a[j] - a[ci] == d) {
			ans += solve(ci, j, k - 1);
		}
	}

	return dp[pi][ci][k] = ans % mod;
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j][k] = -1;
			}
		}
	}

	vector<ll> res = {n};

	for (int k = 2; k <= n; ++k) {
		ll ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans += solve(i, j, k - 2);
			}
		}
		res.push_back(ans % mod);
	}

	for (ll x : res) {
		cout << x << " ";
	}
	cout << endl;
}