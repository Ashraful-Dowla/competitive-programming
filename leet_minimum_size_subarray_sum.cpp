/*
https://leetcode.com/problems/minimum-size-subarray-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;

int pf[100005];

bool solve(int n, int k, int target) {

	for (int i = k; i <= n; ++i) {
		int sum = pf[i] - pf[i - k];
		if (sum >= target) return true;
	}

	return false;
}

int minSubArrayLen(int target, vector<int>& nums) {

	int n = nums.size();

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + nums[i - 1];
	}

	int lo = 1, hi = n, ans = n + 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (solve(n, mid, target)) {
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else lo = mid + 1;

	}

	return ans == n + 1 ? 0 : ans;
}

int main() {
	// int target = 7;
	// vector<int> nums  = {2, 3, 1, 2, 4, 3};

	// int target = 4;
	// vector<int> nums  = {1, 4, 4};

	int target = 11;
	vector<int> nums  = {1, 1, 1, 1, 1, 1, 1, 1};

	cout << minSubArrayLen(target, nums);
}