/*
https://atcoder.jp/contests/abc317/tasks/abc317_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;
const int NN = 1e5 + 10;

int n, total, tt;
vector<int> z;
vector<ll> x, y;
ll dp[N][NN];

ll solve(int i, int seat) {

	if (i == x.size()) {
		if (total < 2 * seat) {
			return 0LL;
		}
		return 1e15;
	}
	if (dp[i][seat] != -1) {
		return dp[i][seat];
	}

	ll ans = 1e15;

	ll xtra = ceil((x[i] + y[i]) / 2.0) - x[i];
	ans = min(ans, solve(i + 1, seat + z[i]) + xtra);
	ans = min(ans, solve(i + 1, seat));

	return dp[i][seat] = ans;

}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		ll xx, yy;
		int zz;

		cin >> xx >> yy >> zz;
		total += zz;

		if (xx > yy) {
			tt += zz;
		}
		else {
			x.push_back(xx);
			y.push_back(yy);
			z.push_back(zz);
		}
	}

	if (total < 2 * tt) {
		cout << 0 << endl;
	}
	else {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= total; ++j) {
				dp[i][j] = -1;
			}
		}

		cout << solve(0, tt) << endl;
	}
}