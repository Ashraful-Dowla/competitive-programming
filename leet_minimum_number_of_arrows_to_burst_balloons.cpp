/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/
#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {

	sort(points.begin(), points.end());

	int n = points.size();
	int st = points[0][0], nd = points[0][1], arrows = 1;

	for (int i = 1; i < n; ++i) {
		if (st <= points[i][0] && points[i][0] <= nd) {
			st = max(st, points[i][0]);
			nd = min(nd, points[i][1]);
		}
		else {
			st = points[i][0], nd = points[i][1];
			arrows++;
		}
	}

	return arrows;
}

int main() {

	// vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
	// vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
	vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

	cout << findMinArrowShots(points);
}