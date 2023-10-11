/*
https://leetcode.com/problems/total-hamming-distance/
*/
#include <bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& nums) {

	int n = nums.size();
	int bits[n][32];

	for (int i = 0; i < n; ++i) {
		for (int j = 31; j >= 0; --j) {
			bits[i][31 - j] = (nums[i] >> j) & 1;
		}
	}

	int sum = 0;
	for (int i = 31; i >= 0; --i) {
		int cnt1 = 0, cnt0 = 0;
		for (int j = 0; j < n; ++j) {
			if (bits[j][i]) cnt1++;
			else cnt0++;
		}

		sum += cnt1 * cnt0;
	}

	return sum;
}

int main() {

	// vector<int> nums = {4, 14, 2};
	vector<int> nums = {4, 14, 4};
	cout << totalHammingDistance(nums) << endl;
}