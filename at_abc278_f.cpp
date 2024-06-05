/*
https://atcoder.jp/contests/abc278/tasks/abc278_f
*/
#include <bits/stdc++.h>
using namespace std;

int n, dp[1 << 17][20];
vector<string> v(20);

bool check(int k, int i) {
	int szk = v[k].size();
	return v[k][szk - 1] == v[i][0];
}

bool solve(int mask, int k) {

	if (dp[mask][k + 1] != -1) {
		return dp[mask][k + 1];
	}

	bool isPossible = false;
	for (int i = 0; i < n; ++i) {
		if (!(mask & (1 << i))) {
			if (k == -1 || check(k, i)) {
				if (!solve(mask | (1 << i), i)) {
					isPossible = true;
				}
			}
		}
	}

	return dp[mask][k + 1] = isPossible;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i <= (1 << n); ++i) {
		for (int k = 0; k <= n; ++k) {
			dp[i][k] = -1;
		}
	}

	cout << (solve(0, -1) ? "First" : "Second") << endl;
}