/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29
*/
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {

	int n = nums.size(), ans = 0;
	for (int i = 0; i < 31; ++i) {
		int one = 0;
		for (int j = 0; j < n; ++j) {
			if ((nums[j] & (1 << i))) {
				one++;
			}
		}

		if ((k & (1 << i))) {
			if (one % 2 == 0) {
				ans++;
			}
		}
		else {
			if (one % 2 == 1) {
				ans++;
			}
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {2, 1, 3, 4};
	// int k = 1;

	vector<int> nums = {2, 0, 2, 0};
	int k = 0;

	cout << minOperations(nums, k) << endl;
}