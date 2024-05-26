/*
https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2024-05-20
*/
#include <bits/stdc++.h>
using namespace std;

int ans;

void subset(vector<int>& nums, int i, int x) {

	if (i == nums.size()) {
		ans += x;
		return ;
	}

	subset(nums, i + 1, x ^ nums[i]);
	subset(nums, i + 1, x);
}

int subsetXORSum(vector<int>& nums) {

	subset(nums, 0, 0);
	return ans;
}

int main() {

	// vector<int> nums = {1, 3};
	// vector<int> nums = {5, 1, 6};
	vector<int> nums = {3, 4, 5, 6, 7, 8};

	cout << subsetXORSum(nums) << endl;
}