#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {

	long long VAL = 10000000007;
	long long first = -VAL, second = -VAL, third = -VAL;

	for (int i = 0; i < nums.size(); ++i) {
		if (first < nums[i] * 1LL) {
			first = nums[i];
		}
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (first > nums[i] * 1LL) {
			if (nums[i] * 1LL > second) {
				third = second;
				second = nums[i];
			}
			else if (nums[i] * 1LL > third && second != nums[i] * 1LL) {
				third = nums[i];
			}
		}
	}

	cout << first << " " << second << " " << third << endl;

	if (nums.size() > 2 && third != -VAL) return third;
	else return first;
}

int main() {

	// vector<int> nums = {3, 2, 1};
	// vector<int> nums = {1, 2};
	// vector<int> nums = {2, 2, 3, 1};
	vector<int> nums = {1, 1, 2};
	cout << thirdMax(nums) << endl;
}