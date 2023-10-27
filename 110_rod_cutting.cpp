#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>prices(N);
int n;
int dp[1004];

//time complexity -> O(N^2)
int cutRod(int len) {
	if (len == 0) return 0;
	if (dp[len] != -1) return dp[len];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (len - i >= 0) {
			ans = max(ans, cutRod(len - i) + prices[i]);
		}
	}
	return dp[len] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> prices[i];
	cout << cutRod(n) << endl;
}