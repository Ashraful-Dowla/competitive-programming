/*
https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27
*/
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {

	deque<int> dq;
	int sum = 1, ans = 0;

	for (int x : nums) {
		sum *= x;
		dq.push_back(x);

		while (!dq.empty() && sum >= k) {
			int d = dq.front();
			dq.pop_front();
			sum /= d;
		}
		ans += dq.size();
	}

	return ans;
}

int main() {


	// vector<int> nums = {10, 5, 2, 6};
	// int k = 100;

	// vector<int> nums = {1, 2, 3};
	// int k = 0;

	vector<int> nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
	int k = 19;
	cout << numSubarrayProductLessThanK(nums, k) << endl;
}