/*
https://leetcode.com/problems/teemo-attacking/
*/
#include <bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {

	vector<pair<int, int>> vec;

	for (int i = 0; i < timeSeries.size(); ++i) {
		vec.push_back({timeSeries[i], timeSeries[i] + duration - 1});
	}

	vec.push_back({INT_MAX, INT_MAX});

	int res = 0;
	for (int i = 0; i + 1 < vec.size(); ++i) {

		int l = vec[i].first, r = vec[i].second, t = vec[i + 1].first;

		if (l <= t && t <= r) {
			res += t - l;
		}
		else {
			res += r - l + 1;
		}
	}

	return res;
}

int main() {

	// vector<int> timeSeries = {1, 4};
	vector<int> timeSeries = {1, 2};
	int duration = 2;

	cout << findPoisonedDuration(timeSeries, duration) << endl;
}