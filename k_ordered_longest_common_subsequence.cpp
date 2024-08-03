#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005][6];

// time complexity -> O(s*t*k)
int solve(vector<int> &s, vector<int> &t, int i, int j, int k) {

	if (i == s.size() || j == t.size()) {
		return 0;
	}
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}

	int c1 = 0, c2 = 0, c3 = 0;
	if (s[i] == t[j]) {
		c1 =  1 + solve(s, t, i + 1, j + 1, k);
	}

	if (k > 0) {
		c2 = 1 + solve(s, t, i + 1, j + 1, k - 1);
	}

	c3 = max(solve(s, t, i + 1, j, k), solve(s, t, i, j + 1, k));

	return dp[i][j][k] = max({c1, c2, c3});
}

int main() {

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> s(n), t(m);

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(s, t, 0, 0, k) << endl;

}