/*
https://leetcode.com/problems/contains-duplicate-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;

bool containsNearbyDuplicate(vector<int>& nums, int k) {

	for (int i = 0; i < nums.size(); ++i) {
		mp[nums[i]].push_back(i);
	}

	for (auto p : mp) {
		vector<int> vec = p.second;
		for (int i = 1; i < vec.size(); ++i) {
			if (vec[i] - vec[i - 1] <= k) return true;
		}
	}

	return false;
}

int main() {

	// int k = 3;
	// vector<int> nums = {1, 2, 3, 1};

	// int k = 1;
	// vector<int> nums = {1, 0, 1, 1};

	int k = 2;
	vector<int> nums = {1, 2, 3, 1, 2, 3};

	cout << containsNearbyDuplicate(nums, k);
}