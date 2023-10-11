/*
https://leetcode.com/problems/sliding-window-median/
*/
#include <bits/stdc++.h>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {

	int n = nums.size();
	multiset<int> ms;

	for (int i = 0; i < k; ++i) {
		ms.insert(nums[i]);
	}

	auto mid = next(ms.begin(), k / 2);

	vector<double> median;
	if (k % 2 == 0) {
		auto mid2 = mid;
		mid2--;
		double m = (double(*mid) + double(*mid2)) / 2.0;
		median.push_back(m);
	}
	else {
		median.push_back(double(*mid));
	}

	for (int i = k; i < n; ++i) {

		ms.insert(nums[i]);
		if (nums[i] < *mid)
			mid--;

		if (nums[i - k] <= *mid)
			mid++;

		ms.erase(ms.lower_bound(nums[i - k]));

		if (k % 2 == 0) {
			auto mid2 = mid;
			mid2--;
			double m = (double(*mid) + double(*mid2)) / 2.0;
			median.push_back(m);
		}
		else {
			median.push_back(double(*mid));
		}

	}

	return median;
}

int main() {

	// vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	// int k = 3;

	// vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
	// int k = 4;

	vector<int> nums = {5, 5, 8, 1, 4, 7, 1, 3, 8, 4};
	int k = 8;

	auto res = medianSlidingWindow(nums, k);

	for (double d : res) {
		cout << d << " ";
	}
}