/*
https://leetcode.com/problems/number-of-boomerangs/
*/
#include <bits/stdc++.h>
using namespace std;

int pw(int x) {
	return x * x;
}

int numberOfBoomerangs(vector<vector<int>>& points) {

	int n = points.size(), ans = 0;
	for (int i = 0; i < n; ++i) {
		int x1 = points[i][0], y1 = points[i][1];
		unordered_map<int, int> cnt;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int x2 = points[j][0], y2 = points[j][1];
			int d = pw(x1 - x2) + pw(y1 - y2);
			cnt[d]++;
		}

		for (auto p : cnt) {
			ans += p.second * (p.second - 1);
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
	// vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
	// vector<vector<int>> points = {{1, 1}};

	cout << numberOfBoomerangs(points);
}