/*
https://leetcode.com/problems/single-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {

	int num = 0;
	for (int x : nums) {
		num ^= x;
	}

	return num;
}

int main() {
	// vector<int> nums = {2, 2, 1};
	vector<int> nums = {4, 1, 2, 1, 2};

	cout << singleNumber(nums);
}