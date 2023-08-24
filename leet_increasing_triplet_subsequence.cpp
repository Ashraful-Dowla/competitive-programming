/*
https://leetcode.com/problems/increasing-triplet-subsequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {

	int n = nums.size();
	vector<int> left(n), right(n);

	left[0] = nums[0];
	right[n - 1] = nums[n - 1];

	for (int i = 1; i < n; ++i) {
		left[i] = min(left[i - 1], nums[i - 1]);
	}

	for (int i = n - 2; i >= 0; --i) {
		right[i] = max(right[i + 1], nums[i + 1]);
	}

	for (int i = 0; i < n; ++i) {
		if (left[i] < nums[i] && nums[i] < right[i]) {
			return true;
		}
	}

	return false;
}

int main() {

	// vector<int> nums = {1, 2, 3, 4, 5};
	// vector<int> nums = {5, 4, 3, 2, 1};
	vector<int> nums = {2, 1, 5, 0, 4, 6};

	cout << increasingTriplet(nums) << endl;
}