/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14
*/
#include <bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int>& nums) {

	int N = 2e5 + 10;
	vector<bool> vis(N, false);

	sort(nums.begin(), nums.end());

	vector<int> nw;
	for (int i = 0; i < nums.size(); ++i) {
		if (vis[nums[i]]) {
			nw.push_back(nums[i]);
		}
		vis[nums[i]] = true;
	}

	int idx = 0, ans = 0;
	for (int i = 0; idx < nw.size() && i < N; ++i) {
		if (nw[idx] > i || vis[i]) continue;
		ans += i - nw[idx];
		vis[i] = true, idx++;
	}

	return ans;
}

int main() {

	// vector<int> nums = {1, 2, 2};
	// vector<int> nums = {3, 2, 1, 2, 1, 7};
	vector<int> nums = {2, 2, 2, 2, 0};

	cout << minIncrementForUnique(nums);
}