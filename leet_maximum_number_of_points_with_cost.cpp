/*
https://leetcode.com/problems/maximum-number-of-points-with-cost/description/?envType=daily-question&envId=2024-08-17
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long maxPoints(vector<vector<int>>& points) {

	int n = points.size();
	int m = points[0].size();

	vector<ll> prev_row(m);

	for (int j = 0; j < m; ++j) {
		prev_row[j] = points[0][j];
	}

	for (int i = 1; i < n; ++i) {

		vector<ll> left(m), right(m), curr_row(m);

		left[0] = prev_row[0];
		for (int j = 1; j < m; ++j) {
			left[j] = max(left[j - 1] - 1, prev_row[j]);
		}

		right[m - 1] = prev_row[m - 1];
		for (int j = m - 2; j >= 0; --j) {
			right[j] = max(right[j + 1] - 1, prev_row[j]);
		}

		for (int j = 0; j < m; ++j) {
			curr_row[j]  = max(left[j], right[j]) + points[i][j];
		}

		prev_row = curr_row;
	}

	ll ans = -1e18;
	for (int j = 0; j < m; ++j) {
		ans = max(ans, prev_row[j]);
	}

	return ans;
}

int main() {

	// vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
	vector<vector<int>> points = {{1, 5}, {2, 3}, {4, 2}};
	cout << maxPoints(points) << endl;
}