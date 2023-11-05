#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N];
int dp[205][20005];

bool subset_sum(int idx, int sum) {
	if (sum == 0) return true;
	if (idx < 0) return false;
	if (dp[idx][sum] != -1) return dp[idx][sum];

	bool isPossible = subset_sum(idx - 1, sum);
	if (sum - arr[idx] >= 0) isPossible |= subset_sum(idx - 1, sum - arr[idx]);
	return dp[idx][sum] = isPossible;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum & 1) cout << false << endl;
	else {
		sum /= 2;
		cout << subset_sum(n - 1, sum) << endl;
	}
}