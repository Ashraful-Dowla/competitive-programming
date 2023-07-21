/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {

	priority_queue<int>pq;

	for (int x : nums) {
		pq.push(x);
	}

	for (int i = 0; i < k - 1; ++i) {
		pq.pop();
	}

	return pq.top();
}

int main() {

	// int k = 2;
	// vector<int> nums = {3, 2, 1, 5, 6, 4};

	int k = 3;
	vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

	cout << findKthLargest(nums, k);
}