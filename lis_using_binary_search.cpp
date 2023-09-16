#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(nlogn)
int lis(vector<int>& nums) {

	vector<int> ans;
	ans.push_back(nums[0]);

	for (int i = 1; i < nums.size(); ++i) {

		if (nums[i] > ans.back()) {
			ans.push_back(nums[i]);
		}
		else {
			int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
			ans[idx] = nums[i];
		}
	}

	return ans.size();
}

int main() {
	vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
	// vector<int> nums = { 3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10 };
	cout << lis(nums) << endl;
}