/*
https://leetcode.com/problems/longest-consecutive-sequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {

	unordered_map<int, int> mp;
	for (int x : nums) {
		mp[x]++;
	}

	int lcs = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int val = nums[i];
		if (mp[val - 1]) continue;

		int len = 0;
		while (mp[val + len]) {
			len++;
		}

		lcs = max(lcs, len);
	}

	return lcs;
}

int main() {
	// vector<int> nums = {100, 4, 200, 1, 2, 3};
	// vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	// vector<int> nums = {1, 2, 0, 1};
	// vector<int> nums = {0};
	// vector<int> nums = {0, 0};
	vector<int> nums = {};

	cout << longestConsecutive(nums);
}