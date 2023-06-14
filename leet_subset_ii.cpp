/*
https://leetcode.com/problems/subsets-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;
map<vector<int>, bool> mp;

void solve(vector<int> &nums, int i) {

	if (i == nums.size()) {
		auto v = temp;
		sort(v.begin(), v.end());

		if (!mp[v]) {
			ans.push_back(v);
			mp[v] = true;
		}

		return;
	}


	temp.push_back(nums[i]);
	solve(nums, i + 1);
	temp.pop_back();

	solve(nums, i + 1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	solve(nums, 0);
	return ans;
}

int main() {
	vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 5};
	// vector<int> nums = {1};

	auto res = subsetsWithDup(nums);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}