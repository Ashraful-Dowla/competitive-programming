/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int kthSmallest(vector<vector<int>> matrix, int k) {

	int n = matrix.size();
	multiset<pair<int, pair<int, int>>> ms;

	ms.insert({matrix[0][0], {0, 0}});
	matrix[0][0] = INT_MAX;
	int cnt = 1;

	while (ms.size() > 0 && cnt++ < k) {
		auto p = *ms.begin();
		ms.erase(ms.begin());

		int x = p.second.first;
		int y = p.second.second;

		if (isValid(x + 1, y, n) && matrix[x + 1][y] != INT_MAX) {
			ms.insert({matrix[x + 1][y], {x + 1, y}});
			matrix[x + 1][y] = INT_MAX;
		}
		if (isValid(x, y + 1, n) && matrix[x][y + 1] != INT_MAX) {
			ms.insert({matrix[x][y + 1], {x, y + 1}});
			matrix[x][y + 1] = INT_MAX;
		}
	}

	auto ans = *ms.begin();
	return ans.first;
}

int main() {

	vector<vector<int>> matrix = {
		{1, 5, 9},
		{10, 11, 13},
		{12, 13, 15}
	};

	// vector<vector<int>> matrix = {
	// 	{ -1}
	// };

	int n = matrix.size();

	for (int k = 1; k <= n * n; ++k) {
		cout << k << "-> " << kthSmallest(matrix, k) << endl;
	}
}