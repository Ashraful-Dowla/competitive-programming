/*
https://leetcode.com/problems/summary-ranges/description/
*/
#include <bits/stdc++.h>
using namespace std;

void add(vector<string>& ans, long st, long rn) {
	if (st == rn - 1) {
		ans.push_back(to_string(st));
	}
	else {
		string s = to_string(st) + "->" + to_string(rn - 1);
		ans.push_back(s);
	}
}

vector<string> summaryRanges(vector<int>& nums) {

	vector<string> ans;

	if (!nums.size()) {
		return ans;
	}

	long st = nums[0], rn = st + 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (rn == nums[i]) {
			rn++;
			continue;
		}

		add(ans, st, rn);
		st = nums[i], rn = st + 1;
	}

	add(ans, st, rn);

	return ans;
}

int main() {

	// vector<int> nums = {0, 1, 2, 4, 5, 7};
	vector<int> nums = {0, 2, 3, 4, 6, 8, 9};

	auto res = summaryRanges(nums);

	for (string s : res) {
		cout << s << endl;
	}
}