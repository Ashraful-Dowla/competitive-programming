/*
https://leetcode.com/problems/zigzag-conversion/
*/
#include <bits/stdc++.h>
using namespace std;


string convert(string s, int numRows) {
	int n = s.size();

	int arr[numRows + 2][n + 5];
	memset(arr, -1, sizeof(arr));

	if (numRows == 1 || s.size() <= numRows) return s;

	int i = 0, l = 0, r = 0;
	while (i < n) {
		for (int j = 0; i < n && j < numRows; ++j) {
			arr[l++][r] = i++;
		}

		--l;
		for (int j = 0; i < n && j + 2 < numRows; ++j) {
			arr[--l][++r] = i++;
		}
		--l, ++r;
	}

	string ans;
	for (int k = 0; k < numRows; ++k) {
		for (int j = 0; j < n + 5; ++j) {
			if (arr[k][j] != -1) {
				ans.push_back(s[arr[k][j]]);
			}
		}
	}

	if (ans.size() == 0) ans = s;

	return ans;
}

int main() {
	int t;
	cin >> t;

	string s;
	int rows;
	while (t--) {
		cin >> s >> rows;
		cout << convert(s, rows) << endl;
	}
}