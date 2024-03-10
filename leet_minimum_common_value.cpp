/*
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/
#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {

	map<int, bool> mp;

	for (int x : nums1) {
		mp[x] = true;
	}

	for (int x : nums2) {
		if (mp[x]) {
			return x;
		}
	}

	return -1;
}

int main() {
	// vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4};
	vector<int> nums1 = {1, 2, 3, 6}, nums2 = {2, 3, 4, 5};


	cout << getCommon(nums1, nums2) << endl;
}