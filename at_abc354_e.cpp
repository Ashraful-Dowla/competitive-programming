/*
https://atcoder.jp/contests/abc354/tasks/abc354_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N], b[N], n, tk, dp[1 << N];

int solve(int mask) {

	if (dp[mask] != -1) {
		return dp[mask];
	}

	bool ok = false;
	for (int i = 0; i < n; ++i) {
		if ((mask & (1 << i))) {
			continue;
		}
		for (int j = i + 1; j < n; ++j) {
			if ((mask & (1 << j))) {
				continue;
			}
			if ((a[i] == a[j] || b[i] == b[j])) {
				if (!solve((mask | (1 << i)) | (1 << j))) {
					ok = true;
				}
			}
		}
	}

	return dp[mask] = ok;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < (1 << n); ++i) {
		dp[i] = -1;
	}

	cout << (solve(0)  ? "Takahashi" : "Aoki") << endl;
}