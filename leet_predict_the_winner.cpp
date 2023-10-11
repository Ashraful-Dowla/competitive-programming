/*
https://leetcode.com/problems/predict-the-winner/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[25][25];

int solve(vector<int>& nums, int i, int j) {

	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int choice1 = nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));
	int choice2 = nums[j] + min(solve(nums, i + 1, j - 1), solve(nums, i, j - 2));

	return dp[i][j] = max(choice1, choice2);
}

bool predictTheWinner(vector<int>& nums) {

	int n = nums.size();

	int total = accumulate(nums.begin(), nums.end(), 0);

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = -1;
		}
	}

	int p1 = solve(nums, 0, n - 1);
	int p2 = total - p1;

	return p1 >= p2;
}

int main() {

	// vector<int> nums = {1, 5, 2};
	vector<int> nums = {1, 5, 233, 7};

	cout << predictTheWinner(nums) << endl;
}