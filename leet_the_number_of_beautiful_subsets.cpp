/*
https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
map<int, bool> taken;
int res;

void solve(vector<int>&nums, int i, int k) {

	if (i >= nums.size()) {
		if (ans.size()) {
			res++;
		}
		return ;
	}

	solve(nums, i + 1, k);

	if (!taken[nums[i]]) {

		ans.push_back(nums[i]);

		taken[nums[i] + k]  = true;
		solve(nums, i + 1, k);
		taken[nums[i] + k]  = false;

		ans.pop_back();
	}
}

int beautifulSubsets(vector<int>& nums, int k) {

	sort(nums.begin(), nums.end());

	solve(nums, 0, k);

	return res;
}

int main() {

	// vector<int> nums = {2, 4, 6};
	// int k = 2;

	// vector<int> nums = {1};
	// int k = 1;

	// vector<int> nums = {10, 4, 5, 7, 2, 1};
	// int k = 3;

	vector<int> nums = {1, 1, 2, 3};
	int k = 1;


	cout << beautifulSubsets(nums, k) << endl;
}