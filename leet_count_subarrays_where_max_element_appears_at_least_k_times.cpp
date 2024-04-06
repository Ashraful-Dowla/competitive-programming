/*
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29
*/
#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {

	int n = nums.size();
	int mx = *max_element(nums.begin(), nums.end());

	unordered_map<int, int>mp;
	deque<int> dq;

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		mp[nums[i]]++;
		dq.push_back(nums[i]);

		while (!dq.empty() && mp[mx] == k) {
			int d = dq.front();
			dq.pop_front();

			mp[d]--;
			ans += n - i;
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 3, 2, 3, 3};
	// int k = 2;

	vector<int> nums = {1, 4, 2, 1};
	int k = 3;

	cout << countSubarrays(nums, k) << endl;
}