/*
https://leetcode.com/problems/majority-element-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {

	int cnt1 = 0, cnt2 = 0;
	int num1 = INT_MIN, num2 = INT_MIN;

	for (int x : nums) {

		if (num1 == x) {
			cnt1++;
		}
		else if (num2 == x) {
			cnt2++;
		}
		else if (cnt1 == 0) {
			num1 = x;
			cnt1 = 1;
		}
		else if (cnt2 == 0) {
			num2 = x;
			cnt2 = 1;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}

	cnt1 = 0, cnt2 = 0;

	for (int x : nums) {
		if (num1 == x) cnt1++;
		else if (num2 == x) cnt2++;
	}

	vector<int> ans;
	int mx = nums.size() / 3;

	if (cnt1 > mx) {
		ans.push_back(num1);
	}
	if (cnt2 > mx) {
		ans.push_back(num2);
	}

	return ans;
}

int main() {

	vector<int> nums = {3, 2, 3};
	// vector<int> nums = {1};
	// vector<int> nums = {1, 2};

	auto res = majorityElement(nums);

	for (auto x : res) {
		cout << x << " ";
	}
}