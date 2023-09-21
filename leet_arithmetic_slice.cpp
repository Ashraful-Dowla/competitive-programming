/*
https://leetcode.com/problems/arithmetic-slices/
*/
#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {

	int ans = 0;
	for (int i = 0; i + 1 < nums.size(); ++i) {
		vector<int> temp = {nums[i], nums[i + 1]};
		int d = nums[i + 1] - nums[i];
		for (int j = i + 2; j < nums.size(); ++j) {
			if (d + temp.back() == nums[j]) {
				temp.push_back(nums[j]);

				if (temp.size() >= 3) {
					ans++;
				}
			}
			else break;
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 2, 3, 4};
	vector<int> nums = {1, 2, 3};
	cout << numberOfArithmeticSlices(nums) << endl;
}