/*
https://leetcode.com/problems/target-sum/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int i, int sum, int target, int total) {

	if (sum > total && sum < 0) return 0;
	if (i == nums.size()) {
		if (target == sum)
			return 1;
		return 0;
	}

	int cnt = solve(nums, i + 1, sum + nums[i], target, total);
	cnt += solve(nums, i + 1, sum - nums[i], target, total);

	return cnt;
}

int findTargetSumWays(vector<int>& nums, int target) {

	int total = accumulate(nums.begin(), nums.end(), 0);
	return solve(nums, 0, 0, target, total);
}

int main() {

	// vector<int> nums = {1, 1, 1, 1, 1};
	// int target = 3;

	// vector<int> nums = {1};
	// int target = 1;

	// vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	// int target = 1;

	vector<int> nums = {33, 36, 38, 40, 25, 49, 1, 8, 50, 13, 41, 50, 29, 27, 18, 25, 37, 8, 0, 48};
	int target = 0;

	// vector<int> nums = {7, 46, 36, 49, 5, 34, 25, 39, 41, 38, 49, 47, 17, 11, 1, 41, 7, 16, 23, 13};
	// int target = 3;

	// vector<int> nums = {2, 7, 9, 13, 27, 31, 37, 3, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 47, 53};
	// int target = 337;

	cout << findTargetSumWays(nums, target);
}