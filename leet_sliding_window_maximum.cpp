/*
https://leetcode.com/problems/sliding-window-maximum/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	deque<int> dq;
	for (int i = 0; i < k; ++i) {

		while (!dq.empty() && nums[dq.back()] <= nums[i]) {
			dq.pop_back();
		}

		dq.push_back(i);
	}

	vector<int> ans;
	ans.push_back(nums[dq.front()]);

	for (int i = k; i < nums.size(); ++i) {

		if (dq.front() == i - k) {
			dq.pop_front();
		}

		while (!dq.empty() && nums[dq.back()] <= nums[i]) {
			dq.pop_back();
		}

		dq.push_back(i);
		ans.push_back(nums[dq.front()]);
	}

	return ans;

}

int main() {

	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;

	// vector<int> nums = {1};
	// int k = 1;

	// vector<int> nums = {1, 3, 1, 2, 0, 5};
	// int k = 3;

	auto res = maxSlidingWindow(nums, k);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}