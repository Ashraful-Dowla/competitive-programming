/*
https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
	{0, 1},
	{1, 0},
	{0, -1},
	{ -1, 0}
};

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

	map<pair<int, int>, bool> mp;

	for (auto v : obstacles) {
		mp[ {v[0], v[1]}] = true;
	}

	int idx = 0, x = 0, y = 0, ans = 0;
	for (int c : commands) {

		if (c == -1) {
			idx = (idx + 1) % 4;
		}
		else if (c == -2) {
			idx = (idx + 3) % 4;
		}
		else {

			int dx = directions[idx].first;
			int dy = directions[idx].second;

			for (int k = 1; k <= c; ++k) {
				if (!mp[ {x + dx, y + dy}]) {
					x += dx;
					y += dy;
					ans = max(ans, x * x + y * y);
				}
				else {
					break;
				}
			}
		}
	}

	return ans;
}

int main() {

	// vector<int> commands = {4, -1, 3};
	// vector<vector<int>> obstacles = {};

	// vector<int> commands = {4, -1, 4, -2, 4};
	// vector<vector<int>> obstacles = {{2, 4}};

	vector<int> commands = {6, -1, -1, 6};
	vector<vector<int>> obstacles = {};



	cout << robotSim(commands, obstacles) << endl;
}