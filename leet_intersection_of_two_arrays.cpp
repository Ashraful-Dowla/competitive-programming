/*
https://leetcode.com/problems/intersection-of-two-arrays/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

	vector<int> cnt(1005, 0);

	for (int x : nums1) {
		if (cnt[x] == 0) cnt[x]++;
	}

	for (int x : nums2) {
		if (cnt[x] == 1) cnt[x]++;
	}

	vector<int> ans;
	for (int i = 0; i <= 1000; ++i) {
		if (cnt[i] == 2) {
			ans.push_back(i);
		}
	}

	return ans;

}

int main() {

	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};

	// vector<int> nums1 = {4, 9, 5};
	// vector<int> nums2 = {9, 4, 9, 8, 4};

	auto res = intersection(nums1, nums2);

	for (int x : res) {
		cout << x << " ";
	}
}