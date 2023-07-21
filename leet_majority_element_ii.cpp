/*
https://leetcode.com/problems/majority-element-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {

	unordered_map<int, int> mp;
	unordered_map<int, bool> taken;

	int mx = nums.size() / 3;
	vector<int> ans;

	for (int x : nums) {
		mp[x]++;
		if (mp[x] > mx && !taken[x]) {
			ans.push_back(x);
			taken[x] = true;
		}
	}

	return ans;
}

int main() {
	// vector<int> nums = {3, 2, 3};
	vector<int> nums = {1};
	// vector<int> nums = {1, 2};

	auto res = majorityElement(nums);

	for (auto x : res) {
		cout << x << " ";
	}
}