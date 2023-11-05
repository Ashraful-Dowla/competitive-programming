/*
https://atcoder.jp/contests/abc322/tasks/abc322_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;

int n, k, p;
vector<ll> cost(105);
int a[105][5];

unordered_map<int, unordered_map<string, ll>> dp;

ll solve(int i, string t) {

	if (i == n) {
		for (int j = 0; j < k; ++j) {
			int num = t[j] - '0';
			if (num < p) return INF;
		}
		return 0;
	}

	if (dp.find(i) != dp.end() && dp[i].find(t) != dp[i].end()) {
		return dp[i][t];
	}

	ll ans = INF;
	string r = t;
	ans = min(ans, solve(i + 1, r));

	for (int j = 0; j < k; ++j) {
		int num = t[j] - '0';
		num = min(p, num + a[i][j]);
		t[j] = num + '0';
	}
	ans = min(ans, solve(i + 1, t) + cost[i]);

	return dp[i][r] = ans;
}

int main() {

	cin >> n >> k >> p;

	string s;
	for (int i = 0; i < k; ++i) {
		s.push_back('0');
	}

	for (int i = 0; i < n; ++i) {
		cin >> cost[i];

		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
		}
	}

	ll ans = solve(0, s);
	cout << (ans == INF ? -1 : ans) << endl;
}