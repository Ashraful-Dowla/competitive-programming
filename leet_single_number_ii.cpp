/*
https://leetcode.com/problems/single-number-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {

	unordered_set<int> st;
	long sum = 0;
	for (int x : nums) {
		st.insert(x);
		sum += x;
	}

	long set_sum = 0;
	for (int x : st) {
		set_sum += x;
	}

	return	(int)((3 * set_sum - sum) / 2);
}

int main() {

	vector<int> nums = {2, 2, 3, 2};
	// vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
	cout << singleNumber(nums);
}