/*
https://leetcode.com/problems/move-zeroes/description/
*/
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {

	int n = nums.size();

	int i = 0, j = 0, z = 0;
	while (i < n && j < n) {
		while (j < n && nums[j] == 0) {
			++j, ++z;
		}
		if (j < n && nums[j] != 0) {
			nums[i++] = nums[j++];
		}
	}

	for (int i = 0; i < z; ++i) {
		nums[n - i - 1] = 0;
	}
}

int main() {

	// vector<int> nums = {0, 1, 0, 3, 12};
	// vector<int> nums = {13, 12};
	vector<int> nums = {0, 1, -1, 1, 0, 0, 0};

	moveZeroes(nums);

	for (int x : nums) {
		cout << x << " ";
	}
	cout << endl;
}