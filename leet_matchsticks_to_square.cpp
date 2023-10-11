/*
https://leetcode.com/problems/matchsticks-to-square/
*/
#include <bits/stdc++.h>
using namespace std;

int sq[4];

bool solve(vector<int>& matchsticks, int len, int idx) {

	if (idx < 0) {
		return true;
	}

	for (int i = 0; i < 4; ++i) {
		if (sq[i] + matchsticks[idx] <= len) {
			sq[i] += matchsticks[idx];
			if (solve(matchsticks, len, idx - 1)) {
				return true;
			}
			sq[i] -= matchsticks[idx];
		}
	}

	return false;
}

bool makesquare(vector<int>& matchsticks) {

	int n = matchsticks.size();

	sort(matchsticks.begin(), matchsticks.end());
	int total_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);

	if (total_len % 4 > 0) return false;

	return solve(matchsticks, total_len / 4, n - 1);
}

int main() {

	vector<int> matchsticks = {1, 1, 2, 2, 2};
	// vector<int> matchsticks = {3, 3, 3, 3, 4};
	// vector<int> matchsticks = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
	// vector<int> matchsticks = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	cout << makesquare(matchsticks) << endl;
}