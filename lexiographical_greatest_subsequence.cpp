#include <bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>& nums, int k) {

	int n = nums.size();
	vector<int> ans;

	for (int i = 0; i < n; ++i) {

		while (ans.size() > 0 && nums[i] > ans.back() && k - ans.size() < n - i) {
			ans.pop_back();
		}

		if (ans.size() < k) {
			ans.push_back(nums[i]);
		}
	}

	return ans;
}

int main() {

	// vector<int> nums = {3, 4, 6, 5};
	// int k = 2;

	vector<int> nums = {9, 1, 2, 5, 8, 3};
	int k = 2;

	auto res = solve(nums, k);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}