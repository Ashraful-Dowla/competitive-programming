/*
https://leetcode.com/problems/maximum-distance-in-arrays/submissions/1357768295/?envType=daily-question&envId=2024-08-16
*/
#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {

	multiset<long long> ms;
	for (auto v : arrays) {
		int sz = v.size();
		ms.insert(v[0]);
		if (sz != 1) {
			ms.insert(v[sz - 1]);
		}
	}

	long long ans = 0;
	for (auto v : arrays) {
		int sz = v.size();
		ms.erase(ms.find(v[0]));
		if (sz != 1) {
			ms.erase(ms.find(v[sz - 1]));
		}

		long long mx = v[sz - 1], mn = v[0];

		ans = max(ans, abs(mn - *ms.rbegin()));
		ans = max(ans, abs(mx - *ms.begin()));

		ms.insert(v[0]);
		if (sz != 1) {
			ms.insert(v[sz - 1]);
		}
	}

	return ans;
}

int main() {

	vector<vector<int>> arrays = {
		{1, 2, 3},
		{4, 5},
		{1, 2, 3}
	};

	cout << maxDistance(arrays) << endl;
}