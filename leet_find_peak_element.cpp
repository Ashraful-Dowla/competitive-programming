/*
https://leetcode.com/problems/find-peak-element/description/
*/
#include <bits/stdc++.h>
using namespace std;

long long check(vector<int>&nums, int mid) {
	if (mid == -1 || mid == nums.size()) return LLONG_MIN;
	return nums[mid];
}

int findPeakElement(vector<int>& nums) {

	int lo = 0, hi = nums.size() - 1;
	int ans;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		long long left = check(nums, mid - 1);
		long long right = check(nums, mid + 1);

		if (left < nums[mid] * 1LL && nums[mid] * 1LL > right) {
			ans = mid;
			break;
		}

		if (left < nums[mid]) lo = mid + 1;
		else hi = mid - 1;
	}

	return ans;
}

int main() {
	vector<int> nums = {1, 2, 3, 1};
	// vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
	// vector<int> nums = { -2147483648};
	// vector<int> nums = {1, 2};

	cout << findPeakElement(nums);
}