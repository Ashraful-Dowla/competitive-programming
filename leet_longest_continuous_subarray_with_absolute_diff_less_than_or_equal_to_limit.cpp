/*
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {

	multiset<int> ms;
	int ans = 0, last = 0;

	for (int i = 0; i < nums.size(); ++i) {

		ms.insert(nums[i]);
		while (ms.size() > 0 && abs(*ms.begin() - *ms.rbegin()) > limit) {
			ms.erase(ms.find(nums[last]));
			last++;
		}

		int sz = ms.size();
		ans = max(ans, sz);
	}

	return ans;
}

int main() {

	// vector<int> nums = {10, 1, 2, 4, 7, 2};
	// int limit = 5;

	// vector<int> nums = {8, 2, 4, 7};
	// int limit = 4;

	vector<int> nums = {1, 5, 6, 7, 8, 10, 6, 5, 6};
	int limit = 4;

	cout << longestSubarray(nums, limit) << endl;
}