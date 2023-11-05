/*
https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int dp[N], h[N];

//time complexity -> O(N)
int func(int n) {
	if (n == 0) return 0;
	if (dp[n] != -1) return dp[n];

	int cost = INT_MAX;

	cost = min(cost, func(n - 1) + abs(h[n] - h[n - 1]));
	if (n > 1) cost = min(cost, func(n - 2) + abs(h[n] - h[n - 2]));
	return dp[n] = cost;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	cout << func(n - 1) << endl;
}