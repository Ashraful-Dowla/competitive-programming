#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[30][300];

ll solve(string s, int i, ll prv) {

	if (i == s.size()) {
		return 1;
	}
	if (dp[i][prv] != -1) {
		return dp[i][prv];
	}

	ll curr = 0, ans = 0;
	for (int j = i; j < s.size(); ++j) {
		curr += (s[j] - '0');
		if (prv <= curr) {
			ans += solve(s, j + 1, curr);
		}
	}

	return dp[i][prv] = ans;
}

int main() {

	int k = 1;
	while (true) {
		string s;
		cin >> s;

		if (s == "bye") {
			break;
		}

		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < 300; ++j) {
				dp[i][j] = -1;
			}
		}

		ll curr = 0, ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			curr += (s[i] - '0');
			ans += solve(s, i + 1, curr);
		}

		cout << k++ << ". " << ans << endl;
	}
}