/*
https://leetcode.com/problems/majority-element/description/
*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	int n = nums.size();

	int cnt = 1, ans;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && nums[i] == nums[i + 1]) cnt++;
		else {
			int r = n / 2;
			if (cnt > r) {
				ans = nums[i];
				break;
			}
			cnt = 1;
		}
	}

	return ans;
}

int main() {

	vector<int> nums = {3, 2, 3};
	// vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

	cout << majorityElement(nums);
}