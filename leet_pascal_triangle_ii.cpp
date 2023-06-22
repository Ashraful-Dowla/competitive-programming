/*
https://leetcode.com/problems/pascals-triangle-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void generate(int numRows) {

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
}

vector<int> getRow(int rowIndex) {
	generate(rowIndex + 1);
	return ans[rowIndex];
}

int main() {

	int rowIndex = 4;
	vector<int> ans = getRow(rowIndex);

	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}