/*
https://leetcode.com/problems/freedom-trail/description/?envType=daily-question&envId=2024-04-27
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int solve(string &ring, string &key, int i, int k) {

	if (i >= key.size()) {
		return 0;
	}
	if (dp[i][k] != -1) {
		return dp[i][k];
	}

	int ans = 1e6, n = ring.size();
	for (int j = 0; j < n; ++j) {
		if (key[i] == ring[j]) {

			int r1 = (j - k + n) % n;
			int r2 = (2 * n + k - j) % n;

			ans = min(ans, solve(ring, key, i + 1, j) + min(r1, r2) + 1);
		}
	}

	return dp[i][k] = ans;
}

int findRotateSteps(string ring, string key) {

	for (int i = 0; i <= key.size(); ++i) {
		for (int j = 0; j <= ring.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	return solve(ring, key, 0, 0);
}

int main() {

	// string ring = "godding", key = "gd";
	// string ring = "godding", key = "godding";
	// string ring = "edcba", key = "abcde";
	string ring = "abc", key = "aaccbb";

	cout << findRotateSteps(ring, key) << endl;
}