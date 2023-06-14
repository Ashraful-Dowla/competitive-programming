/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
	int lo = 0, hi = nums.size() - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (nums[mid] == target) return true;
		else if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
			lo++, hi--;
		}
		else if (nums[lo] <= nums[mid]) {
			if (nums[lo] <= target && target <= nums[mid]) {
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		else {
			if (nums[mid] <= target && target <= nums[hi]) {
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
	}

	return false;
}

int main() {
	// vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
	//vector<int> nums = {1, 0, 1, 1, 1};
	vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
	//vector<int> nums = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
	int target = 0;

	cout << search(nums, target);
}