/*
https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {

	vector<pair<int, int>> res;
	for (int i = 0; i < score.size(); ++i) {
		res.push_back({score[i], i});
	}

	sort(res.rbegin(), res.rend());

	int sz = score.size();
	vector<string> ans(sz);

	map<int, string> mp = {
		{0, "Gold Medal"},
		{1, "Silver Medal"},
		{2, "Bronze Medal"}
	};

	for (int i = 0; i < min(3, sz); ++i) {
		ans[res[i].second] = mp[i];
	}

	for (int i = 3; i < sz; ++i) {
		int x = i + 1;
		ans[res[i].second] = to_string(x);
	}

	return ans;
}

int main() {

	// vector<int> score = {5, 4, 3, 2, 1};
	vector<int> score = {10, 3, 8, 9, 4};

	auto res = findRelativeRanks(score);

	for (string x : res) {
		cout << x << endl;
	}
}