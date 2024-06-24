/*
https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
*/
#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {

	int n = nums.size();
	vector<int> odf(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		if (nums[i - 1] % 2) {
			odf[i] = odf[i - 1] + 1;
		}
		else {
			odf[i] = odf[i - 1];
		}
	}

	multiset<int> ms;
	for (int i = 0; i < k; ++i) {
		ms.insert(odf[i]);
	}

	int ans = 0;
	for (int i = k; i <= n; ++i) {
		ans += ms.count(odf[i] - k);
		ms.insert(odf[i]);
	}

	return ans;
}

int main() {

	vector<int> nums = {1, 1, 2, 1, 1};
	int k = 3;

	cout << numberOfSubarrays(nums, k) << endl;
}