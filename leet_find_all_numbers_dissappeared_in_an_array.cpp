/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {

	for (int i = 0; i < nums.size(); ++i) {
		int idx = abs(nums[i]) - 1;
		nums[idx] = -1 * abs(nums[idx]);
	}

	vector<int> ans;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0) {
			ans.push_back(i + 1);
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> nums = {1, 1};

	auto res = findDisappearedNumbers(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}