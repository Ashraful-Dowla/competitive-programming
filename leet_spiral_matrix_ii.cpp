/*
https://leetcode.com/problems/spiral-matrix-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool taken[30][30];

bool isValid(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

vector<pair<int, int>> direction = {
	{0, 1},
	{1, 0},
	{0, -1},
	{ -1, 0}
};

vector<pair<int, int>> traject = {
	{1, -1},
	{ -1, -1},
	{ -1, 1},
	{1, 1}
};

vector<vector<int>> generateMatrix(int n) {

	int d = 0;
	int x = 0, y = 0;

	int arr[n][n];

	int cnt = 1;
	while (cnt <= n * n) {
		while (isValid(x, y, n) && !taken[x][y]) {
			arr[x][y] = cnt++;
			taken[x][y] = true;

			x += direction[d].first;
			y += direction[d].second;
		}

		x += traject[d].first;
		y += traject[d].second;
		d++;
		d %= 4;
	}

	vector<vector<int>> ans;
	for (int i = 0; i < n; ++i) {
		vector<int> temp;
		for (int j = 0; j < n; ++j) {
			temp.push_back(arr[i][j]);
		}

		ans.push_back(temp);
	}

	return ans;
}

int main() {
	int n = 5;
	generateMatrix(n);
}