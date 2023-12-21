/*
https://atcoder.jp/contests/abc303/tasks/abc303_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

ll x, y, z, dp[N][2];
string s;

ll solve(int i, bool caps) {

	if (i == s.size()) {
		return 0;
	}
	if (dp[i][caps] != -1) {
		return dp[i][caps];
	}

	ll ans = 1e16;
	if (caps) {

		if (s[i] == 'A') {
			ans = min(ans, solve(i + 1, caps) + x);
			ans = min(ans, solve(i + 1, 1 - caps) + y + z);
		}
		else {
			ans = min(ans, solve(i + 1, caps) + y);
			ans = min(ans, solve(i + 1, 1 - caps) + z + x);
		}

	}
	else {
		if (s[i] == 'a') {
			ans = min(ans, solve(i + 1, caps) + x);
			ans = min(ans, solve(i + 1, 1 - caps) + y + z);
		}
		else {
			ans = min(ans, solve(i + 1, caps) + y);
			ans = min(ans, solve(i + 1, 1 - caps) + z + x);
		}
	}

	return dp[i][caps] = ans;
}

int main() {

	cin >> x >> y >> z;
	cin >> s;

	for (int i = 0; i <= s.size(); ++i) {
		dp[i][0] = dp[i][1] = -1;
	}

	cout << solve(0, 0) << endl;
}