/*
https://leetcode.com/problems/missing-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

	int sum = 0;
	for (int x : nums) {
		sum += x;
	}

	int n = nums.size();
	int total = n * (n + 1);
	total /= 2;

	return total - sum;
}

int main() {
	// vector<int> nums = {3, 0, 1};
	// vector<int> nums = {0, 1};
	vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

	cout << missingNumber(nums);
}