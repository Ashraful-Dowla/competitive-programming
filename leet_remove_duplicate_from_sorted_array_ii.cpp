/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {

	int k = 1, idx = 0;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1]) {
			for (int j = 0; j < min(2, k); ++j) {
				nums[idx++] = nums[i - 1];
			}
			k = 1;
		}
		else k++;
	}

	for (int j = 0; j < min(2, k); ++j) {
		nums[idx++] = nums[nums.size() - 1];
	}

	return idx;
}

int main() {
	// vector<int> nums = {1, 1, 1, 2, 2, 3};
	// vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
	vector<int> nums = {2, 1, 1, 1, 1};

	int k = removeDuplicates(nums);
	cout << k << endl;

	for (int i = 0; i < k; ++i) {
		cout << nums[i] << " ";
	}
}