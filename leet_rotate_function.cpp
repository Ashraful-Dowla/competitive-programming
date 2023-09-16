/*
https://leetcode.com/problems/rotate-function/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {

	int n = nums.size();
	int rotate_sum = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		rotate_sum += i * nums[i];
		sum += nums[i];
	}

	int ans = rotate_sum;

	for (int i = n - 1; i >= 1; --i) {
		int d = sum - n * nums[i];
		rotate_sum += d;
		ans = max(ans, rotate_sum);
	}

	return ans;
}

int main() {

	// vector<int> nums = {4, 3, 2, 6};
	vector<int> nums = {100};
	cout << maxRotateFunction(nums) << endl;
}