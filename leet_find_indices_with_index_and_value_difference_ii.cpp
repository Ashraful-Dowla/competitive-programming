/*
https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {

	set<pair<int, int>> s;
	for (int i = indexDifference; i < nums.size(); ++i) {
		s.insert({nums[i], i});
	}

	for (int i = 0; i + indexDifference < nums.size(); ++i) {

		auto p = *s.begin();
		if (abs(nums[i] - p.first) >= valueDifference) {
			return {i, p.second};
		}

		auto q = *s.rbegin();
		if (abs(nums[i] - q.first) >= valueDifference) {
			return {i, q.second};
		}

		s.erase(s.find({nums[i + indexDifference], i + indexDifference}));
	}

	return { -1, -1};
}

int main() {

	// vector<int> nums = {5, 1, 4, 1};
	// int indexDifference = 2;
	// int valueDifference = 4;

	// vector<int> nums = {2, 1};
	// int indexDifference = 0;
	// int valueDifference = 0;

	vector<int> nums = {1, 2, 3};
	int indexDifference = 2;
	int valueDifference = 4;


	auto res = findIndices(nums, indexDifference, valueDifference);

	cout << res[0] << " " << res[1] << endl;
}