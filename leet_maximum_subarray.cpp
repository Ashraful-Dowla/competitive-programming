#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/maximum-subarray/
*/
int maxSubArray(vector<int>& nums) {
	int sum = 0, best = INT_MIN;

	for (int i = 0; i < nums.size(); ++i) {
		sum = max(nums[i], sum + nums[i]);
		best = max(best, sum);
	}

	return  best;
}

int main() {
	// vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	// vector<int> nums = {5, 4, -1, 7, 8};
	vector<int> nums = {1};

	cout << maxSubArray(nums) << endl;
}