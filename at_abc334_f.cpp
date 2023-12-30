/*
https://atcoder.jp/contests/abc334/tasks/abc334_f
*/
#include<bits/stdc++.h>
using namespace std;

typedef long double ll;

const int N = 2e5 + 10;
vector<ll> X(N, 0), Y(N, 0), dis(N), dp(N, 1e15), pf(N, 0), delta(N, 0);

ll euclid_dis(int i, int j) {
	ll res = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
	return sqrt(res);
}

int main() {

	int n, k;
	cin >> n >> k;


	cin >> X[0] >> Y[0];

	for (int i = 1; i <= n; ++i) {
		cin >> X[i] >> Y[i];
	}

	for (int i = 1; i <= n; ++i) {
		dis[i] = euclid_dis(0, i);
	}

	for (int i = 2; i <= n; ++i) {
		pf[i] = pf[i - 1] + euclid_dis(i, i - 1);
	}

	for (int i = 1; i <= n; ++i) {
		delta[i] = dis[i] + dis[i + 1] - pf[i + 1];
	}

	dp[1] = dis[1];

	multiset<ll> ms;
	ms.insert(dp[1] + delta[1]);

	for (int i = 2; i <= n; ++i) {

		dp[i] = *ms.begin() + pf[i];

		if (k >= i) {
			dp[i] = min(dp[i], dp[i - 1] + euclid_dis(i, i - 1));
		}

		ms.insert(dp[i] + delta[i]);

		if (ms.size() > k) {
			ms.erase(ms.find(dp[i - k] + delta[i - k]));
		}
	}

	cout << fixed << setprecision(10) << dp[n] + delta[n] << endl;
}