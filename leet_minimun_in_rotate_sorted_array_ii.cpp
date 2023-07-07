/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
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
		if (nums[lo] == nums[hi]) {
			ans = min(ans, nums[lo]);
			lo++, hi--;
			continue;
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
	// vector<int> nums = {1, 3, 5};
	vector<int> nums = {2, 2, 2, 0, 1};

	cout << findMin(nums);
}