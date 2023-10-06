/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
*/
#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums) {

	int n = nums.size();
	int mn = *min_element(nums.begin(), nums.end());

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += nums[i] - mn;
	}

	return res;
}

int main() {

	vector<int> nums = {1, 2, 3};
	// vector<int> nums = {1, 1, 1};

	cout << minMoves(nums) << endl;

}