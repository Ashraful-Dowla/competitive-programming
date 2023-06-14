/*
https://leetcode.com/problems/merge-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	int k = m + n - 1;
	int l = m - 1, r = n - 1;
	while (l >= 0 && r >= 0) {
		if (nums1[l] >= nums2[r]) {
			nums1[k--] = nums1[l--];
		}
		else nums1[k--] = nums2[r--];
	}

	while (l >= 0) {
		nums1[k--] = nums1[l--];
	}

	while (r >= 0) {
		nums1[k--] = nums2[r--];
	}

	for (int i = 0; i < m + n; ++i) {
		cout << nums1[i] << " ";
	}
	cout << endl;
}

int main() {
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums1 = {0};
	// vector<int> nums2 = {2, 5, 6};
	vector<int> nums2 = {1};

	// int m = 3, n = 3;
	int m = 0, n = 1;

	merge(nums1, m, nums2, n);
}