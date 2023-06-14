/*
https://leetcode.com/problems/subsets/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(vector<int> &nums, int idx) {

	if (idx == nums.size()) {
		ans.push_back(temp);
		return ;
	}

	temp.push_back(nums[idx]);
	solve(nums, idx + 1);
	temp.pop_back();

	solve(nums, idx + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	solve(nums, 0);
	return ans;
}

int main() {
	// vector<int> nums = {1, 2, 3};
	vector<int> nums = {0};

	auto res = subsets(nums);

	for (auto v : res) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}