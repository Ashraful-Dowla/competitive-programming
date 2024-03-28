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

ll solve(string &s, int i) {

	if (i >= s.size()) {
		return 1;
	}
	if (dp[i] != -1) {
		return dp[i];
	}

	ll ans = 0;
	string p = string(1, s[i]);

	if (alpha(stoi(p))) {
		ans += solve(s, i + 1);
	}

	if (p != "0" && i + 1 < s.size()) {
		p += string(1, s[i + 1]);
		if (alpha(stoi(p))) {
			ans += solve(s, i + 2);
		}
	}

	return dp[i] = ans;
}

int main() {

	while (true) {
		string s;
		cin >> s;
		if (s == "0") break;

		for (int i = 0; i <= s.size(); ++i) {
			dp[i] = -1;
		}

		cout << solve(s, 0) << endl;
	}
}