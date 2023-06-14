#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int dp[N][N];

// time complexity -> O(N^3)
int mcm(vector<int>&vec, int l, int r) {

	if (l >= r) return 0;

	if (dp[l][r] != -1) return dp[l][r];

	int res = INT_MAX;
	for (int k = l; k < r; ++k) {
		int left = mcm(vec, l, k);
		int right = mcm(vec, k + 1, r);
		int cost = vec[l - 1] * vec[k] * vec[r];

		res = min(res, left + right + cost);
	}

	return dp[l][r] = res;
}

int main() {
	// vector<int> vec = {40, 20, 30, 10, 30};
	vector<int> vec = {10, 30, 5, 60};

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec.size(); ++j) {
			dp[i][j] = -1;
		}
	}

	cout << mcm(vec, 1, vec.size() - 1);
}