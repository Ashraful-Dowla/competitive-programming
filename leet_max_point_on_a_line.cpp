/*
https://leetcode.com/problems/max-points-on-a-line/description/
*/
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {

	int n = points.size();
	unordered_map<float, int>mp;

	int mx = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {

			float slope;
			if (points[i][0] == points[j][0]) {
				slope = 300005;
			}
			else {
				float dx = points[i][0] - points[j][0];
				float dy = points[i][1] - points[j][1];

				slope = dy / dx;
			}

			mx = max(mx, ++mp[slope]);
		}
		mp.clear();
	}

	return mx + 1;
}

int main() {

	// vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
	vector<vector<int>> points = {{1, 1}, {3, 2},
		{5, 3}, {4, 1}, {2, 3}, {1, 4}
	};

	// vector<vector<int>> points = {
	// 	{0, 0},
	// 	{94911151, 94911150},
	// 	{94911152, 94911151}
	// };

	cout << maxPoints(points);
}