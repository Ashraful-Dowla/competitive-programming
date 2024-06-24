/*
https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
*/
#include <bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {

	int n = nums.size();
	vector<int> pf(3 * n, 0);

	int ans = 0;
	for (int i = 0; i < n; ++i) {

		if (i > 0) {
			pf[i] += pf[i - 1];
		}

		if (nums[i] == 0) {
			if (pf[i] % 2 == 0) {
				if (i + k <= n) {
					ans++;
					pf[i]++;
					pf[i + k]--;
				}
				else return -1;
			}
		}
		else {
			if (pf[i] % 2 == 1) {
				if (i + k <= n) {
					ans++;
					pf[i]++;
					pf[i + k]--;
				}
				else return -1;
			}
		}
	}

	return ans;
}

int main() {

	vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
	int k = 3;

	// vector<int> nums = {0, 1, 0};
	// int k = 1;

	// vector<int> nums = {1, 1, 0};
	// int k = 2;

	cout << minKBitFlips(nums, k) << endl;
}