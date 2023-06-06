/*
https://leetcode.com/problems/insert-interval/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

	vector<int> t;
	t.push_back(INT_MAX);
	t.push_back(INT_MAX);

	intervals.push_back(t);
	intervals.push_back(newInterval);

	sort(intervals.begin(), intervals.end());

	vector<vector<int>> ans;
	int start = intervals[0][0];

	for (int i = 0; i < intervals.size() - 1; ++i) {
		if (intervals[i][1] < intervals[i + 1][0]) {

			vector<int> temp;
			temp.push_back(start);
			temp.push_back(intervals[i][1]);

			ans.push_back(temp);
			start = intervals[i + 1][0];
		}
		else {
			intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
		}
	}

	return ans;
}

int main() {
	// vector<vector<int>> intervals = {{1, 3}, {6, 9}};
	vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

	// vector<int> newInterval = {2, 5};
	vector<int> newInterval = {4, 8};

	auto res = insert(intervals, newInterval);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << endl;
	}
}