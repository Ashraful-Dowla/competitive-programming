/*
https://www.spoj.com/problems/ACODE/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5005;
ll dp[N];

bool alpha(int n) {
	return n >= 1 && n <= 26;
}

int main() {

	while (true) {
		string s;
		cin >> s;

		if (s == "0") break;

		int n = s.size();
		s = "_" + s;

		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i] = 0;
		}

		for (int i = 1; i <= n; ++i) {

			string p = string(1, s[i]);

			if (alpha(stoi(p))) {
				dp[i] += dp[i - 1];
			}

			if (i >= 2 && s[i - 1] != '0') {
				p = string(1, s[i - 1]) + string(1, s[i]);
				if (alpha(stoi(p))) {
					dp[i] += dp[i - 2];
				}
			}
		}

		cout << dp[n] << endl;
	}
}