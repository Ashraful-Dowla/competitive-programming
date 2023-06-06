/*
https://leetcode.com/problems/jump-game/description/
*/
#include <bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
	int n = nums.size();

	int reach = 0;
	for (int i = 0; i < n; ++i) {
		if (reach < i) return false;
		reach = max(reach, i + nums[i]);
	}

	return true;
}

int main() {
	// vector<int> nums = {2, 3, 1, 1, 4};
	vector<int> nums = {3, 2, 1, 0, 4};

	// canJump(nums);
	cout << canJump(nums) << endl;
}