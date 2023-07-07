/*
https://leetcode.com/problems/maximum-gap/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maximumGap(vector<int>& nums) {

	int n = nums.size();
	if (n < 2) return 0;

	int mx = *max_element(nums.begin(), nums.end());
	int mn = *min_element(nums.begin(), nums.end());

	int range = ceil((mx - mn) * 1.0 / (n - 1) * 1.0);

	vector<int> b_max(n - 1, -1), b_min(n - 1, INT_MAX);

	for (int i = 0; i < n; ++i) {
		if (nums[i] == mn || nums[i] == mx) continue;

		int idx = (nums[i] - mn) / range;

		b_min[idx] = min(b_min[idx], nums[i]);
		b_max[idx] = max(b_max[idx], nums[i]);
	}

	int prev = mn, ans = 0;

	for (int i = 0; i < n - 1; ++i) {
		if (b_max[i] == -1) continue;

		ans = max(ans, b_min[i] - prev);
		prev = b_max[i];
	}

	ans = max(ans, mx - prev);

	return ans;

}

int main() {

	vector<int> nums = {3, 6, 9, 1};
	cout << maximumGap(nums);
}