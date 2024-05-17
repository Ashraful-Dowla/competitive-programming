/*
https://atcoder.jp/contests/abc281/tasks/abc281_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
vector<ll> v;
int n;
ll d, dp[105][105][105];

ll solve(int i, int k, ll rem) {

	if (k == 0) {
		return rem == 0 ? 0 : -INF;
	}
	if (i >= n) {
		return -INF;
	}
	if (dp[i][k][rem] != -1) {
		return dp[i][k][rem];
	}


	ll ans = -INF;
	ans = max(ans, solve(i + 1, k - 1, (rem + v[i]) % d) + v[i]);
	ans = max(ans, solve(i + 1, k, rem));

	return dp[i][k][rem] = ans;
}


int main() {

	int k;
	cin >> n >> k >> d;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int l = 0; l < d; ++l) {
				dp[i][j][l] = -1;
			}
		}
	}

	ll res = solve(0, k, 0);
	cout << (res < 0 ? -1 : res) << endl;
}