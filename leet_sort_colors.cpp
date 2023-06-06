/*
https://leetcode.com/problems/sort-colors/description/
*/
#include <bits/stdc++.h>
using namespace std;

//dutch national flag algo(DNF)
// time complexity -> O(N)

void sortColors(vector<int>& nums) {

	int lo = 0, mid = 0, hi = nums.size() - 1;

	while (mid <= hi) {
		if (nums[mid] == 0) {
			swap(nums[lo], nums[mid]);
			lo++, mid++;
		}
		else if (nums[mid] == 1) mid++;
		else {
			swap(nums[mid], nums[hi]);
			hi--;
		}
	}
}

int main() {
	// vector<int> nums = {2, 0, 2, 1, 1, 0};
	vector<int> nums = {2, 0, 1};

	sortColors(nums);

	for (auto x : nums) {
		cout << x << " ";
	}
}