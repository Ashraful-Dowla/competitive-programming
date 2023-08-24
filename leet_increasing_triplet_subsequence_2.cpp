/*
https://leetcode.com/problems/increasing-triplet-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {

	int n = nums.size();

	if (n < 3) return false;

	long left = INT_MAX, mid = INT_MAX;

	for (int i = 0; i < n; ++i) {

		if (nums[i] > mid) return true;
		else if (nums[i] > left && nums[i] < mid) mid = nums[i];
		else if (nums[i] < left) left = nums[i];

	}

	return false;
}

int main() {

	// vector<int> nums = {1, 2, 3, 4, 5};
	// vector<int> nums = {5, 4, 3, 2, 1};
	// vector<int> nums = {2, 1, 5, 0, 4, 6};
	vector<int> nums = {20, 100, 10, 12, 5, 13};

	cout << increasingTriplet(nums) << endl;
}