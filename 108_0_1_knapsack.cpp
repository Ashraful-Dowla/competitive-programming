#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int wt[N], val[N];

long long dp[105][100050];

//O(N*W)
long long knapsack(int idx, int left_wt) {
	if (left_wt == 0) return 0;
	if (idx < 0) return 0;
	if (dp[idx][left_wt] != -1) return dp[idx][left_wt];
	long long ans = knapsack(idx - 1, left_wt); // item not taken
	if (left_wt - wt[idx] >= 0) {
		ans = max(ans, knapsack(idx - 1, left_wt - wt[idx]) + val[idx]); // item taken
	}
	return dp[idx][left_wt] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		cin >> wt[i] >> val[i];
	}
	cout << knapsack(n - 1, w);
}