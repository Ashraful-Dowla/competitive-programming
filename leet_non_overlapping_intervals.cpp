/*
https://leetcode.com/problems/non-overlapping-intervals/
*/
#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

	sort(intervals.begin(), intervals.end());

	int l = 0, r = 1, cnt = 0, n = intervals.size();

	while (r < n) {
		if (intervals[l][1] <= intervals[r][0]) {
			l = r;
			r++;
		}
		else if (intervals[l][1] <= intervals[r][1]) {
			cnt++;
			r++;
		}
		else if (intervals[l][1] > intervals[r][1]) {
			l = r;
			r++;
			cnt++;
		}
	}

	return cnt;

}

int main() {


	// vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
	// vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
	// vector<vector<int>> intervals = {{1, 2}, {2, 3}};
	// vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
	vector<vector<int>> intervals = {
		{ -52, 31}, { -73, -26}, {82, 97}, { -65, -11},
		{ -62, -49}, {95, 99}, {58, 95}, { -31, 49},
		{66, 98}, { -63, 2}, {30, 47}, { -40, -26}
	};

	cout << eraseOverlapIntervals(intervals);
}