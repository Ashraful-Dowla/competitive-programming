/*
https://leetcode.com/problems/partition-equal-subset-sum/
*/
#include <bits/stdc++.h>
using namespace std;

int dp[21000][300];

bool solve(vector<int>& nums, int sum, int subsum, int i) {

	if (sum == 2 * subsum) return true;
	if (i == nums.size()) return false;
	if (dp[subsum][i] != -1) return dp[subsum][i];

	bool isPossible = solve(nums, sum, subsum + nums[i], i + 1);
	isPossible |= solve(nums, sum, subsum, i + 1);

	return dp[subsum][i] = isPossible;
}

bool canPartition(vector<int>& nums) {

	int sum = accumulate(nums.begin(), nums.end(), 0);

	for (int i = 0; i <= sum; ++i) {
		for (int j = 0; j <= nums.size(); ++j) {
			dp[i][j] = -1;
		}
	}
	return solve(nums, sum, 0, 0);
}

int main() {

	// vector<int>  nums = {1, 5, 11, 5};
	vector<int>  nums = {1, 2, 3, 5};
	cout << canPartition(nums) << endl;
}