/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14
*/
#include <bits/stdc++.h>
using namespace std;

int count_pairs(vector<int>&nums, int dis) {

	int l = 0, cnt = 0;
	for (int r = 0; r < nums.size(); ++r) {
		while (nums[r] - nums[l] > dis) {
			l++;
		}
		cnt += r - l;
	}

	return cnt;
}

int smallestDistancePair(vector<int>& nums, int k) {

	int n = nums.size();
	sort(nums.begin(), nums.end());

	int lo = 0, hi = nums[n - 1] - nums[0];

	while (lo < hi) {
		int mid = (hi + lo) / 2;

		if (count_pairs(nums, mid) < k) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}

	return lo;
}

int main() {

	// vector<int> nums = {1, 6, 1};
	// int k = 3;

	vector<int> nums = {62, 100, 4};
	int k = 2;

	cout << smallestDistancePair(nums, k) << endl;
}