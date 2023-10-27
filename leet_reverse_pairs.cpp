/*
https://leetcode.com/problems/reverse-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int l, int r, int mid, int& ans) {

	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (nums[i] * 1LL > 2 * 1LL * nums[j]) {
			ans += (mid - i + 1);
			++j;
		}
		else ++i;
	}

	int l_sz = mid - l + 1;
	int r_sz = r - mid;

	long long L[l_sz + 1], R[r_sz + 1];

	for (int k = 0; k < l_sz; ++k) {
		L[k] = nums[l + k];
	}

	for (int k = 0; k < r_sz; ++k) {
		R[k] = nums[mid + 1 + k];
	}

	L[l_sz] = R[r_sz] = LLONG_MAX;

	int l_i = 0, r_i = 0;
	for (int k = l; k <= r; ++k) {

		if (L[l_i] <= R[r_i]) {
			nums[k] = L[l_i];
			l_i++;
		}
		else {
			nums[k] = R[r_i];
			r_i++;
		}
	}
}

void merge_sort(vector<int>& nums, int l, int r, int& ans) {

	if (l == r) return;

	int mid = (l + r) / 2;
	merge_sort(nums, l, mid, ans);
	merge_sort(nums, mid + 1, r, ans);
	merge(nums, l, r, mid, ans);
}

int reversePairs(vector<int>& nums) {

	int n = nums.size(), ans = 0;
	merge_sort(nums, 0, n - 1, ans);
	return ans;
}

int main() {

	vector<int> nums = {1, 3, 2, 3, 1};
	// vector<int> nums = {2, 4, 3, 5, 1};
	// vector<int> nums = {5, 4, 3, 2, 1};

	cout << reversePairs(nums) << endl;
}