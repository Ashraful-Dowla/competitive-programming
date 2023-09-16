/*
https://leetcode.com/problems/russian-doll-envelopes/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
	if (v1[0] == v2[0]) {
		return v1[1] > v2[1];
	}
	return v1[0] < v2[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {

	sort(envelopes.begin(), envelopes.end(), cmp);

	vector<int> heights;
	for (int i = 0; i < envelopes.size(); ++i) {
		heights.push_back(envelopes[i][1]);
	}

	vector<int> ans;
	ans.push_back(heights[0]);

	for (int i = 1; i < heights.size(); ++i) {
		if (heights[i] > ans.back()) {
			ans.push_back(heights[i]);
		}
		else {
			int idx = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
			ans[idx] = heights[i];
		}
	}

	return ans.size();
}

int main() {

	vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
	// vector<vector<int>> envelopes = {{1, 1}, {1, 1}, {1, 1}};

	cout << maxEnvelopes(envelopes);
}