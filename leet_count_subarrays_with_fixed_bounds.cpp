/*
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/submissions/1220949341/?envType=daily-question&envId=2024-03-31
*/
#include <bits/stdc++.h>
using namespace std;

long long countSubarra1ys(vector<int>& nums, int minK, int maxK) {

	long long ans = 0;
	int last_min_i = -1, last_max_i = -1, last_invalid_i = -1;

	for (int i = 0; i < nums.size(); ++i) {

		if (minK <= nums[i] && nums[i] <= maxK) {
			if (nums[i] == minK) {
				last_min_i = i;
			}
			if (nums[i] == maxK) {
				last_max_i = i;
			}

			ans += max(0, min(last_max_i, last_min_i) - last_invalid_i);
		}
		else {
			last_invalid_i = i;
			last_min_i = last_max_i = -1;
		}

	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 3, 5, 2, 7, 5};
	// int minK = 1, maxK = 5;

	vector<int> nums = {1, 1, 1, 1};
	int minK = 1, maxK = 1;

	cout << countSubarrays(nums, minK, maxK) << endl;
}