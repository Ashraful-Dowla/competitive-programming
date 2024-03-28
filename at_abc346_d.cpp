/*
https://atcoder.jp/contests/abc346/tasks/abc346_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const ll INF = 1e15;
int n;
ll c[N], dp[N][2][2];
string s;

ll solve(int i, int prv, bool t) {

	if (i >= n) {
		return t ? INF : 0;
	}
	if (dp[i][prv][t] != -1) {
		return dp[i][prv][t];
	}

	int v = s[i] - '0';
	ll ans = INF;

	if (t) {
		if (v == prv) {
			ans = min(ans, solve(i + 1, v, 1 - t));
			ans = min(ans, solve(i + 1, 1 - v, t) + c[i]);
		}
		else {
			ans = min(ans, solve(i + 1, v, t));
			ans = min(ans, solve(i + 1, 1 - v, 1 - t) + c[i]);
		}
	}
	else {
		if (v == prv) {
			ans = min(ans, solve(i + 1, 1 - v, t) + c[i]);
		}
		else {
			ans = min(ans, solve(i + 1, v, t));
		}
	}

	return dp[i][prv][t] = ans;
}

int main() {

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	int v = s[0] - '0';
	ll ans = solve(1, v, true);
	ans = min(ans, solve(1, 1 - v, true) + c[0]);
	cout << ans << endl;
}