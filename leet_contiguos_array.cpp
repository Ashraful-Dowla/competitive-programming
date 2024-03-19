/*
https://leetcode.com/problems/contiguous-array/submissions/1204998830/?envType=daily-question&envId=2024-03-16
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {

	int ans = 0, sum = 0;
	map<int, int> mp;

	mp[0] = 0;
	for (int i = 1; i <= nums.size(); ++i) {
		if (nums[i - 1] == 0) sum--;
		else sum++;

		if (mp.find(sum) != mp.end()) {
			ans = max(ans, i - mp[sum]);
		}
		else {
			mp[sum] = i;
		}

	}

	return ans;
}

int main() {

	// vector<int> nums = {0, 1};
	// vector<int> nums = {0, 1, 0};
	// vector<int> nums = {0, 0, 1, 1};
	// vector<int> nums = {0, 1, 0, 1};

	vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1};

	cout << findMaxLength(nums) << endl;

}