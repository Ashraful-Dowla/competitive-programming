#include <bits/stdc++.h>
using namespace std;

const int N = 4;
vector<vector<int>> dis = {
	{0, 20, 42, 35},
	{20, 0, 30, 34},
	{42, 30, 0, 12},
	{35, 34, 12, 0}
};

// const int N = 4;
// vector<vector<int>> dis = {
// 	{ 0, 10, 15, 20 },
// 	{ 10, 0, 25, 25 },
// 	{ 15, 25, 0, 30 },
// 	{ 20, 25, 30, 0 },
// };

int dp[N][1 << N];

// time complexity -> O(2^N * N^2)
int tsp(int pos, int mask) {

	if (__builtin_popcount(mask) == N) {
		return dis[pos][0];
	}
	if (dp[pos][mask] != -1) {
		return dis[pos][mask];
	}

	int ans = INT_MAX;
	for (int nxt = 0; nxt < N; ++nxt) {
		if (!(mask & (1 << nxt))) {
			ans = min(ans, tsp(nxt, mask | 1 << nxt) + dis[pos][nxt]);
		}
	}

	return dis[pos][mask] = ans;
}
int main() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (1 << N); ++j) {
			dp[i][j] = -1;
		}
	}

	cout << tsp(0, 1) << endl;
}