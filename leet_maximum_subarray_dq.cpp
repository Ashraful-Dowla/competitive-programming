#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/maximum-subarray/description/
*/
int max_cross_sum_subarray(vector<int> &nums, int lo, int mid, int hi) {

	int left_sum = INT_MIN;
	int sum = 0;

	for (int i = mid; i >= lo; --i) {
		sum += nums[i];
		left_sum = max(left_sum, sum);
	}

	int right_sum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= hi; ++i) {
		sum += nums[i];
		right_sum = max(right_sum, sum);
	}

	return left_sum + right_sum;
}

int max_sum_subarray(vector<int> &nums, int lo, int hi) {

	if (lo == hi) return nums[lo];

	int mid = (lo + hi) / 2;
	int left_sum = max_sum_subarray(nums, lo, mid);
	int right_sum = max_sum_subarray(nums, mid + 1, hi);

	int cross_sum = max_cross_sum_subarray(nums, lo, mid, hi);

	return max({left_sum, right_sum, cross_sum});
}

//divide and conquer
int maxSubArray(vector<int>& nums) {
	return max_sum_subarray(nums, 0, nums.size() - 1);
}

int main() {
	// vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> nums = {5, 4, -1, 7, 8};
	// vector<int> nums = {1};

	cout << maxSubArray(nums);
}