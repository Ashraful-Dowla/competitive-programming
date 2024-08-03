/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
*/
#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int>& nums) {

	int sz = nums.size();

	if (sz <= 4) {
		return 0;
	}

	sort(nums.begin(), nums.end());

	long long ans  = 1e18;
	for (int i = 0; i <= 3; ++i) {
		int left = i;
		int right = 3 - i;

		ans = min(ans, 1LL * nums[sz - right - 1] - 1LL * nums[left]);
	}

	return ans;
}

int main() {

	// vector<int> nums = {5, 3, 2, 4};
	// vector<int> nums = {6, 6, 0, 1, 1, 4, 6};
	vector<int> nums = {82, 81, 95, 75, 20};

	cout << minDifference(nums) << endl;
}