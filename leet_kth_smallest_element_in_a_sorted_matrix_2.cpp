/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
*/
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {

	int n = matrix.size();
	multiset<pair<int, pair<int, int>>> ms;

	for (int r = 0; r < n; ++r) {
		ms.insert({matrix[r][0], {r, 0}});
	}

	int cnt = 0;
	while (ms.size() > 0) {
		auto p = *ms.begin();
		cnt++;

		if (cnt == k) break;
		ms.erase(ms.begin());

		int x = p.second.first;
		int y = p.second.second;

		if (y + 1 < n) {
			ms.insert({matrix[x][y + 1], {x, y + 1}});
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