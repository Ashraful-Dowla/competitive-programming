/*
https://leetcode.com/problems/non-decreasing-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;
map<vector<int>, bool> taken;

void solve(vector<int>& nums, int i) {

	if (i == nums.size()) {
		if (temp.size() > 1 && !taken[temp]) {
			ans.push_back(temp);
			taken[temp] = true;
		}
		return ;
	}

	if (temp.empty() || temp.back() <= nums[i]) {

		temp.push_back(nums[i]);
		solve(nums, i + 1);
		temp.pop_back();
	}

	solve(nums, i + 1);
}

vector<vector<int>> findSubsequences(vector<int>& nums) {

	solve(nums, 0);
	return ans;
}

int main() {

	vector<int> nums = {4, 6, 7, 7};
	// vector<int> nums = {4, 4, 3, 2, 1};
	auto res = findSubsequences(nums);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}