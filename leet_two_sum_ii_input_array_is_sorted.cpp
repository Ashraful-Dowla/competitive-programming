/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

	int n = numbers.size();

	vector<int> ans;
	for (int i = 0; i < n; ++i) {

		int val = target - numbers[i];
		int lo = i + 1, hi = n - 1;

		while (lo <= hi) {

			int mid = (lo + hi) / 2;

			if (numbers[mid] == val) {
				ans.push_back(i + 1);
				ans.push_back(mid + 1);
				break;
			}
			else if (numbers[mid] < val) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
	}

	return ans;
}

int main() {
	// vector<int> numbers = {2, 7, 11, 15};
	// int target = 9;

	// vector<int> numbers = {2, 3, 4};
	// int target = 6;

	vector<int> numbers = { -1, 0};
	int target = -1;


	auto res = twoSum(numbers, target);

	cout << res[0] << " " << res[1] << endl;
}