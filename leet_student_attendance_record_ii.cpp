/*
https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
const int N = 1e5 + 10;

ll dp[N][2][3];

ll solve(int n, int i, int a, int l) {

	if (i == n) {
		return 1;
	}
	if (dp[i][a][l] != -1) {
		return dp[i][a][l];
	}

	ll ans = 0;

	if (a > 0) {
		ans += solve(n, i + 1, a - 1, 2);
	}
	if (l > 0) {
		ans += solve(n, i + 1, a, l - 1);
	}

	ans += solve(n, i + 1, a, 2);

	return dp[i][a][l] = ans % M;
}

int checkRecord(int n) {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	return solve(n, 0, 1, 2);
}

int main() {

	int n = 10101;
	cout << checkRecord(n) << endl;
}