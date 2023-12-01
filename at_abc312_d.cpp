/*
https://atcoder.jp/contests/abc312/tasks/abc312_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3005;
const ll M = 998244353;

ll dp[N][N];

int main() {

	string s;
	cin >> s;

	int n = s.size();
	s = '_' + s;

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (s[i] == '(' || s[i] == '?') {
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % M;
			}

			if (j > 0 && (s[i] == ')' || s[i] == '?')) {
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % M;
			}
		}
	}

	cout << dp[n][0] << endl;

}