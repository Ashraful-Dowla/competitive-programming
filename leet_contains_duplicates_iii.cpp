/*
https://leetcode.com/problems/contains-duplicate-iii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

	set<long> s;
	for (int i = 0; i < nums.size(); ++i) {

		if (i > indexDiff) s.erase(nums[i - indexDiff - 1]);

		long n = nums[i];

		// |x-n| <= valdiff
		// x-n <= valdiff => x - n<= valdif
		// or -(x-n) <= valdiff => x-n >= -valdiff => x >= n - valdiff
		auto res = s.lower_bound(n - valueDiff);

		if (res != s.end() && *res - n <= valueDiff) {
			return true;
		}
		s.insert(n);
	}

	return false;
}

int main() {

	// int indexDiff = 3;
	// int valueDiff = 0;
	// vector<int> nums = {1, 2, 3, 1};


	// int indexDiff = 2;
	// int valueDiff = 3;
	// vector<int> nums = {1, 5, 9, 1, 5, 9};

	int indexDiff = 1;
	int valueDiff = 2;
	vector<int> nums = {1, 3, 6, 2};

	cout << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

}