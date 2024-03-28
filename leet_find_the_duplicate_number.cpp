/*
https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24
*/
#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	int lo = 0, hi = nums.size() - 1, ans = -1;

	while (lo < hi) {
		if (nums[lo] == nums[lo + 1]) {
			ans = nums[lo];
			break;
		}
		else if (nums[hi] == nums[hi - 1]) {
			ans = nums[hi];
			break;
		}
		else {
			lo++, hi--;
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 3, 4, 2, 2};
	// vector<int> nums = {3, 1, 3, 4, 2};
	vector<int> nums = {3, 3, 3, 3, 3};

	cout << findDuplicate(nums) << endl;
}