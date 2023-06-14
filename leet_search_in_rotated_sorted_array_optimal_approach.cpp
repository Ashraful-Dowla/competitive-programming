/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;


// time complexity -> O(logn)
int search(vector<int>& nums, int target) {

	int lo = 0, hi = nums.size() - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (nums[mid] == target) return mid;
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

	return -1;
}

int main() {
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int target = 2;

	cout << search(nums, target);
}