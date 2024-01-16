/*
https://leetcode.com/problems/3sum/description/
*/

#include <bits/stdc++.h>
using namespace std;

map<vector<int>, bool> mp;

vector<vector<int>> threeSum(vector<int>& nums) {

	int n = nums.size();
	sort(nums.begin(), nums.end());

	vector<vector<int>> ans;

	for (int i = 0; i < n; ++i) {
		int lo = i + 1, hi = n - 1;

		vector<int> temp;
		while (lo < hi) {
			int sum = nums[i] + nums[lo] + nums[hi];

			if (sum == 0) {
				temp.push_back(nums[i]);
				temp.push_back(nums[lo]);
				temp.push_back(nums[hi]);

				if (!mp[temp]) {
					ans.push_back(temp);
					mp[temp] = true;
				}
				lo++, hi--;
				temp.clear();
			}
			else if (sum > 0) hi--;
			else lo++;
		}
	}

	return ans;
}

int main() {
	// vector<int> nums = {-1,0,1,2,-1,-4};
	// vector<int> nums = {0,0,0,0};
	vector<int> nums = { -2, 0, 1, 1, 2};

	vector<vector<int>> vec = threeSum(nums);

	for (auto v : vec) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}