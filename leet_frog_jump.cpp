/*
https://leetcode.com/problems/frog-jump/
*/
#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> dp;

bool solve(vector<int>& stones, int i, int k) {

	if (i + 1 == stones.size()) return true;
	if (i > stones.size()) return false;
	if (dp.find({i, k}) != dp.end()) return dp[ {i, k}];

	bool isPossible = false;
	if (i == 0) {
		int value = stones[i] + 1;
		auto it = lower_bound(stones.begin() + i + 1, stones.end(), value);

		if (it != stones.end() && *it == value) {
			int idx = it - stones.begin();
			isPossible |= solve(stones, idx, 1);
		}
	}
	else {
		for (int kk = k - 1; kk <= k + 1; ++kk) {
			int value = stones[i] + kk;
			auto it = lower_bound(stones.begin() + i + 1, stones.end(), value);

			if (it != stones.end() && *it == value) {
				int idx = it - stones.begin();
				isPossible |= solve(stones, idx, kk);
			}
		}

	}


	return dp[ {i, k}] = isPossible;
}

bool canCross(vector<int>& stones) {
	return solve(stones, 0, 1);
}

int main() {

	// vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
	// vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
	vector<int> stones = {0, 2};

	cout << canCross(stones) << endl;
}