/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int>& nums) {

	int ans = -1;

	map<int, bool> mp;

	for (int x : nums) {
		mp[x] = true;
	}

	for (int x : nums) {
		if (mp[-x]) {
			ans = max(ans, abs(x));
		}
	}

	return ans;
}

int main() {

	vector<int> nums = { -1, 2, -3, 3};

	cout << findMaxK(nums) << endl;
}