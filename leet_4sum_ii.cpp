/*
https://leetcode.com/problems/4sum-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                 vector<int>& nums3, vector<int>& nums4) {

	int n1 = nums1.size();
	int n2 = nums2.size();

	int n3 = nums3.size();
	int n4 = nums4.size();


	unordered_map<int, int> mp1;
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			mp1[nums1[i] + nums2[j]]++;
		}
	}

	unordered_map<int, int> mp2;
	for (int i = 0; i < n3; ++i) {
		for (int j = 0; j < n4; ++j) {
			mp2[nums3[i] + nums4[j]]++;
		}
	}

	int ans = 0;
	for (auto p : mp1) {
		int x = p.first;
		if (mp2[-x] > 0) {
			ans += (mp1[x] * mp2[-x]);
		}
	}

	return ans;

}

int main() {

	vector<int> nums1 = {1, 2}, nums2 = { -2, -1}, nums3 = { -1, 2}, nums4 = {0, 2};
	// vector<int> nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};
	cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
}