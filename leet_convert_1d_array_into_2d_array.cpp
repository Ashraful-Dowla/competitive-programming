/*
https://leetcode.com/problems/convert-1d-array-into-2d-array/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

	vector<vector<int>> a(m, vector<int>(n));

	if (original.size() != m * n) {
		return {};
	}

	for (int i = 0; i < original.size(); ++i) {
		a[i / n][i % n] = original[i];
	}

	return a;
}

int main() {

	vector<int> original = {1, 2, 3, 4};
	int m = 2, n = 2;

	auto res = construct2DArray(original, m, n);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}