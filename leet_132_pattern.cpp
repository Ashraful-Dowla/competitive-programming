/*
https://leetcode.com/problems/132-pattern/
*/
#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {

	stack<pair<int, int>> stk;

	int mn = nums[0], n = nums.size();

	for (int i = 1; i < n; ++i) {

		while (!stk.empty() && stk.top().first <= nums[i]) {
			stk.pop();
		}

		if (!stk.empty() && nums[i] > stk.top().second) {
			return true;
		}

		stk.push({nums[i], mn});
		mn = min(mn, nums[i]);
	}

	return false;
}

int main() {

	// vector<int> nums = {1, 2, 3, 4};
	// vector<int> nums = {3, 1, 4, 2};
	// vector<int> nums = { -1, 3, 2, 0};
	// vector<int> nums = {1, 4, 1, 2};
	vector<int> nums = {1, 4};

	cout << find132pattern(nums) << endl;
}