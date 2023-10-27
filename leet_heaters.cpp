/*
https://leetcode.com/problems/heaters/
*/
#include <bits/stdc++.h>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {

	sort(heaters.begin(), heaters.end());
	int m = heaters.size();

	int ans = 0;
	for (int h : houses) {
		int idx = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();

		int r = idx >= m ? INT_MAX : heaters[idx] - h;
		int l = idx < 1 ? INT_MAX : h - heaters[idx - 1];

		ans = max(ans, min(l, r));
	}

	return ans;
}

int main() {

	// vector<int> houses = {1,2,3};
	// vector<int> heaters = {2};

	// vector<int> houses = {1, 2, 3, 4};
	// vector<int> heaters = {1, 4};

	vector<int> houses = {1, 5};
	vector<int> heaters = {2};

	cout << findRadius(houses, heaters) << endl;
}