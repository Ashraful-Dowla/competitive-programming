/*
https://leetcode.com/problems/squares-of-a-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {

	int n = 1e4 + 2;
	vector<int> cnt(n, 0);

	for (int x : nums) {
		cnt[abs(x)]++;
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			ans.push_back(i * i);
		}
	}

	return ans;

}

int main() {


	// vector<int> nums = { -4, -1, 0, 3, 10};
	vector<int> nums = { -7, -3, 2, 3, 11};
	auto res = sortedSquares(nums);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}