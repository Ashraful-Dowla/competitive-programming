/*
https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14
*/
#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {

	int sum = 0;
	unordered_map<int, int> mp;

	int ans = 0;
	for (int x : nums) {
		sum += x;
		ans += mp[sum - goal];

		if (sum == goal) {
			ans++;
		}

		mp[sum]++;
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 0, 1, 0, 1};
	// int goal = 2;

	vector<int> nums = {0,0,0,0,0};
	int goal = 0;

	cout << numSubarraysWithSum(nums, goal) << endl;
}