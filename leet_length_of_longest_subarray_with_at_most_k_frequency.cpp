/*
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {

	unordered_map<int, int> mp;
	deque<int> dq;
	int ans = 0;

	for (int i = 0; i < nums.size(); ++i) {

		dq.push_back(nums[i]);
		mp[nums[i]]++;

		while (!dq.empty() && mp[nums[i]] > k) {
			int d = dq.front();
			dq.pop_front();
			mp[d]--;
		}
		int sz = dq.size();
		ans = max(ans, sz);
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
	// int k = 2;

	// vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2};
	// int k = 1;

	vector<int> nums = {5, 5, 5, 5, 5, 5, 5};
	int k = 4;

	cout << maxSubarrayLength(nums, k) << endl;
}