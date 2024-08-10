/*
https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
	{0, 1},
	{1, 0},
	{0, -1},
	{ -1, 0}
};

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {


	vector<vector<int>> ans;
	ans.push_back({rStart, cStart});

	for (int st = 1, d = 0; ans.size() < rows * cols;) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < st; ++j) {
				rStart += directions[d].first;
				cStart += directions[d].second;
				if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
					ans.push_back({rStart, cStart});
				}
			}
			d++;
			d %= 4;
		}
		++st;
	}

	return ans;
}

int main() {

	int rows = 5;
	int cols = 6;
	int rStart = 1;
	int cStart = 4;

	auto res = spiralMatrixIII(rows, cols, rStart, cStart);

	for (auto r : res) {
		for (int x : r) {
			cout << x << " ";
		}
		cout << endl;
	}
}