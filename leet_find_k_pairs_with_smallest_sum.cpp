/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<pair<int, int>, bool> taken;

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

	n = nums1.size();
	m = nums2.size();

	multiset<pair<long long, pair<int, int>>> ms;
	vector<vector<int>>ans;

	ms.insert({1LL * nums1[0] + nums2[0], {0, 0}});
	taken[ {0, 0}] = true;

	while (ms.size() > 0 && ans.size() != k) {
		auto p = *ms.begin();
		ms.erase(ms.begin());

		int x = p.second.first;
		int y = p.second.second;

		ans.push_back({nums1[x], nums2[y]});

		if (isValid(x + 1, y) && !taken[ {x + 1, y}]) {
			ms.insert({1LL * nums1[x + 1] + nums2[y], {x + 1, y}});
			taken[ {x + 1, y}] = true;
		}
		if (isValid(x , y + 1) && !taken[ {x, y + 1}]) {
			ms.insert({1LL * nums1[x] + nums2[y + 1], {x, y + 1}});
			taken[ {x, y + 1}] = true;
		}
	}

	return ans;
}

int main() {

	vector<int> nums1 = {1, 7, 11};
	vector<int> nums2 = {2, 4, 6};
	int k = 3;

	// vector<int> nums1 = {1, 1, 2};
	// vector<int> nums2 = {1, 2, 3};
	// int k = 2;

	// vector<int> nums1 = {1, 2};
	// vector<int> nums2 = {3};
	// int k = 3;

	auto res = kSmallestPairs(nums1, nums2, k);

	for (auto v : res) {
		cout << v[0] << " " << v[1] << endl;
	}
}