/*
https://leetcode.com/problems/permutations-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
	map<vector<int>, bool> mp;
	vector<vector<int>> ans;

	sort(nums.begin(), nums.end());

	do {
		if (!mp[nums]) {
			mp[nums] = true;
			ans.push_back(nums);
		}
	} while (next_permutation(nums.begin(), nums.end()));

	return ans;
}

int main() {
	vector<int> nums = {1, 2, 3};

	vector<vector<int>> ans = permuteUnique(nums);

	for (auto v : ans) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}