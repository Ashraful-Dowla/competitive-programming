/*
https://leetcode.com/problems/merge-intervals/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

	vector<int> t;
	t.push_back(INT_MAX);
	t.push_back(INT_MAX);

	intervals.push_back(t);

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
	// vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	// vector<vector<int>> intervals = {{1, 4}, {4, 5}};
	// vector<vector<int>> intervals = {{1, 4}, {5, 6}};
	// vector<vector<int>> intervals = {{1, 4}, {0, 4}};
	// vector<vector<int>> intervals = {{1, 4}, {0, 0}};
	vector<vector<int>> intervals = {{1, 4}, {2, 3}};

	auto res = merge(intervals);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << endl;
	}
}