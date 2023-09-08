/*
https://leetcode.com/problems/largest-divisible-subset/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, vector<int>> dp;

vector<int> solve(vector<int>& nums, int i, int j) {

	if (dp.find({i, j}) != dp.end()) {
		return dp[ {i, j}];
	}

	vector<int> res1, res2;
	for (int k = j; k >= 0; --k) {
		if (nums[i] % nums[k] == 0) {
			res1 = solve(nums, k, k - 1);
			res1.push_back(nums[k]);

			res2 = solve(nums, i, k - 1);

			return dp[ {i, j}] = (res1.size() > res2.size() ? res1 : res2);
		}
	}

	return dp[ {i, j}] = (res1.size() > res2.size() ? res1 : res2);
}

vector<int> largestDivisibleSubset(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	vector<int> ans;
	for (int i = nums.size() - 1; i >= 0; --i) {

		auto res = solve(nums, i, i - 1);
		res.push_back(nums[i]);

		if (res.size() > ans.size()) {
			ans = res;
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 2, 4, 8};
	// vector<int> nums = {1, 2, 3};
	vector<int> nums = {1, 2, 4, 8, 9, 72};

	auto v = largestDivisibleSubset(nums);

	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}