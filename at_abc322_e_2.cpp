/*
https://atcoder.jp/contests/abc322/tasks/abc322_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;

int n, k, p;
vector<ll> cost(105);
int a[105][5];

ll dp[105][6][6][6][6][6];

ll solve(int i, int i0, int i1, int i2, int i3, int i4) {

	if (i == n) {
		if (i0 < p && 0 < k) return INF;
		if (i1 < p && 1 < k) return INF;
		if (i2 < p && 2 < k) return INF;
		if (i3 < p && 3 < k) return INF;
		if (i4 < p && 4 < k) return INF;
		return 0;
	}

	if (dp[i][i0][i1][i2][i3][i4] != -1) {
		return dp[i][i0][i1][i2][i3][i4];
	}

	ll ans = INF;

	ans = min(ans, solve(i + 1,
	                     min(p, i0 + a[i][0]),
	                     min(p, i1 + a[i][1]),
	                     min(p, i2 + a[i][2]),
	                     min(p, i3 + a[i][3]),
	                     min(p, i4 + a[i][4])) + cost[i]);

	ans = min(ans, solve(i + 1, i0, i1, i2, i3, i4));

	return dp[i][i0][i1][i2][i3][i4] = ans;
}

int main() {

	cin >> n >> k >> p;


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int l = 0; l < 6; ++l) {
				for (int m = 0; m < 6; ++m) {
					for (int o = 0; o < 6; ++o) {
						for (int q = 0; q < 6; ++q) {
							dp[i][j][l][m][o][q] = -1;
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < n; ++i) {
		cin >> cost[i];

		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
		}
	}

	ll ans = solve(0, 0, 0, 0, 0, 0);
	cout << (ans == INF ? -1 : ans) << endl;
}