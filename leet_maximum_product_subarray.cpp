/*
https://leetcode.com/problems/maximum-product-subarray/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {

	int res = *max_element(nums.begin(), nums.end());

	int curr_max = 1, curr_min = 1;

	for (auto n : nums) {

		if (n == 0) {
			curr_max = curr_min = 1;
			continue;
		}

		int temp_curr_max = curr_max;
		curr_max = max({ n * temp_curr_max, n * curr_min, n});
		curr_min = min({ n * temp_curr_max, n * curr_min, n});

		res = max({res, curr_max, curr_min});
	}

	return res;

}

int main() {

	vector<int> nums = {2, 3, -2, 4};
	// vector<int> nums = { -2, 0, -1, -4};
	cout << maxProduct(nums);
}