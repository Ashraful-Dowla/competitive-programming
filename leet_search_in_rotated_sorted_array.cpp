/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

//time complexity -> O(3logn)
int search(vector<int>& nums, int target) {

	int n = nums.size();
	int lo = 0, hi = n - 1;

	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (nums[0] < nums[mid]) lo = mid;
		else hi = mid;
	}

	auto it = lower_bound(nums.begin(), nums.begin() + lo, target);

	if (*it == target) return it - nums.begin();

	it = lower_bound(nums.begin() + lo + 1, nums.end(), target);

	if (it == nums.end() || *it != target) return -1;
	else return it - nums.begin();
}

int main() {

	vector<int> nums = {1, 3};
	int target = 2;

	cout << search(nums, target) << endl;
}