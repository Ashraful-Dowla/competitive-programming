/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

	unordered_map<int, int> mp1, mp2;

	for (int x : nums1) {
		mp1[x]++;
	}

	for (int x : nums2) {
		mp2[x]++;
	}

	vector<int> ans;
	for (auto p : mp1) {
		int n = min(p.second, mp2[p.first]);

		for (int i = 0; i < n; ++i) {
			ans.push_back(p.first);
		}
	}

	return ans;
}

int main() {

	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};

	auto res = intersect(nums1, nums2);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}