/*
https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
*/
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {

	int pf = 0, ans = 0;
	unordered_map<int, int> mp;

	int c = (1e9) / k;
	c *= k;

	for (int x : nums) {
		pf += x;

		int mod = (pf + c) % k;
		ans += mp[mod];

		if (mod == 0) {
			ans++;
		}
		mp[mod]++;
	}

	return ans;
}

int main() {


	// vector<int> nums = {4, 5, 0, -2, -3, 1};
	vector<int> nums = {9, 9};
	int k = 9;


	cout << subarraysDivByK(nums, k) << endl;
}