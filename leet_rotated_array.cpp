#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k %= n;

	reverse(nums.begin(), nums.begin() + (n - k));
	reverse(nums.begin() + (n - k), nums.end());
	reverse(nums.begin(), nums.end());
}

int main() {

	// vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	// int k = 3;

	vector<int> nums = { -1, -100, 3, 99};
	int k = 4;

	rotate(nums, k);

	for (auto x : nums) {
		cout << x << " ";
	}
}