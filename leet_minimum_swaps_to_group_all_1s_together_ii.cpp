/*
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02
*/
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums) {

	int n = nums.size();

	vector<int> v;
	for (int i = 0; i < 2; ++i) {
		for (int x : nums) {
			v.push_back(x);
		}
	}

	vector<int> pf(2 * n + 1, 0);

	for (int i = 1; i <= 2 * n; ++i) {
		pf[i] = pf[i - 1] + v[i - 1];
	}

	int k = pf[n];
	int ans = n;

	for (int i = k; i <= 2 * n; ++i) {
		ans = min(ans, pf[n] - pf[i] + pf[i - k]);
	}

	return ans;
}

int main() {

	vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
	// vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
	// vector<int> nums = {1, 1, 0, 0, 1};

	cout << minSwaps(nums) << endl;
}