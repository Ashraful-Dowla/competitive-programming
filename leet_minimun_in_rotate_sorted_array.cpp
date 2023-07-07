/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {

	int n = nums.size();
	int lo = 0, hi = n - 1;

	int ans = 5005;
	while (lo <= hi) {

		if (nums[lo] < nums[hi]) {
			ans = min(ans, nums[lo]);
			break;
		}

		int mid = (hi + lo) / 2;
		ans = min(ans, nums[mid]);

		if (nums[lo] <= nums[mid]) {
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	return ans;
}

int main() {
	// vector<int> nums = {3, 4, 5, 1, 2};
	// vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	// vector<int> nums = {11, 13, 15, 17};
	// vector<int> nums = {6, 1, 3, 4};
	vector<int> nums = { -1, 1, 3, 4, 5};
	// vector<int> nums = {5, 1, 2, 3, 4};

	cout << findMin(nums);
}