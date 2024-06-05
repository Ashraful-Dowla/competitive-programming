/*
https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
*/
#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int>& nums) {

	for (int x = 0; x <= 100; ++x) {
		int ct = 0;
		for (int v : nums) {
			if (v >= x) {
				ct++;
			}
		}

		if (ct == x) {
			return x;
		}
	}

	return -1;
}

int main() {

	// vector<int> nums = {0, 4, 3, 0, 4};
	// vector<int> nums = {0, 0};
	vector<int> nums = {3, 5};

	cout << specialArray(nums) << endl;
}