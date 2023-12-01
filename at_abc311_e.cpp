/*
https://atcoder.jp/contests/abc311/tasks/abc311_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[3005][3005], dp[3005][3005];

int main() {

	int h, w, n;
	cin >> h >> w >> n;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			a[i][j] = 1;
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 0;
	}

	for (int i = 1; i <= h; ++i) {
		dp[i][1] = a[i][1];
	}

	for (int i = 1; i <= w; ++i) {
		dp[1][i] = a[1][i];
	}

	for (int i = 2; i <= h; ++i) {
		for (int j = 2; j <= w; ++j) {
			if (a[i][j] == 0) continue;
			dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
		}
	}

	ll sum = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			sum += dp[i][j];
		}
	}

	cout << sum << endl;
}