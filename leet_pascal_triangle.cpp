/*
https://leetcode.com/problems/pascals-triangle/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {

	vector<vector<int>> ans;

	for (int i = 0; i < numRows; ++i) {
		vector<int> row;
		row.push_back(1);

		for (int j = 1; j < i; ++j) {
			int res = ans[i - 1][j] + ans[i - 1][j - 1];
			row.push_back(res);
		}

		if (i > 0) row.push_back(1);

		ans.push_back(row);
	}

	return ans;

}

int main() {
	int numRows = 10;

	auto res = generate(numRows);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}