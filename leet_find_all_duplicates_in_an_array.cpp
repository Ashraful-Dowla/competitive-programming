/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25
*/
#include <bits/stdc++.h>
using namespace std;


vector<int> findDuplicates(vector<int>& nums) {

	vector<int> ans;
	for (int i = 0; i < nums.size(); ++i) {

		int p = abs(nums[i]);

		if (nums[p - 1] > 0) {
			nums[p - 1] *= -1;
		}
		else {
			ans.push_back(p);
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	// vector<int> nums = {1, 1, 2};
	vector<int> nums = {1};

	auto res = findDuplicates(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}