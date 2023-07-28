/*
https://leetcode.com/problems/missing-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

	int num = 0;
	for (int x : nums) {
		num ^= x;
	}

	int n = nums.size();
	for (int i = 0; i <= n; ++i) {
		num ^= i;
	}

	return num;
}

int main() {
	vector<int> nums = {3, 0, 1};
	// vector<int> nums = {0, 1};
	// vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

	cout << missingNumber(nums);
}