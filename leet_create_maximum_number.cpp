/*
https://leetcode.com/problems/create-maximum-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> greatest_subsequence(vector<int>& nums, int len) {

	int n = nums.size();
	vector<int> res;

	for (int i = 0; i < n; ++i) {

		while (res.size() > 0 && nums[i] > res.back() && len - res.size() < n - i) {
			res.pop_back();
		}

		if (res.size() < len) {
			res.push_back(nums[i]);
		}
	}

	return res;
}

vector<int> solve(vector<int>& v1, vector<int>& v2, int k) {

	vector<int> res;
	for (int i = 0; i < k; ++i) {

		vector<int> temp = max(v1, v2);
		int mx = temp.front();

		if (v1 > v2) {
			v1.erase(v1.begin());
		}
		else {
			v2.erase(v2.begin());
		}

		res.push_back(mx);
	}

	return res;
}


vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

	vector<int> ans;
	for (int i = 0; i <= k; ++i) {

		if (i > nums1.size() || k - i > nums2.size()) {
			continue;
		}

		vector<int> res1 = greatest_subsequence(nums1, i);
		vector<int> res2 = greatest_subsequence(nums2, k - i);
		vector<int> res = solve(res1, res2, k);

		ans = max(ans, res);
	}

	return ans;
}

int main() {

	vector<int> nums1 = {3, 4, 6, 5}, nums2 = {9, 1, 2, 5, 8, 3};
	int  k = 5;

	// vector<int> nums1 = {6, 7}, nums2 = {6, 0, 4};
	// int  k = 5;

	// vector<int> nums1 = {3, 9}, nums2 = {8, 9};
	// int  k = 3;


	auto res = maxNumber(nums1, nums2, k);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;

}
