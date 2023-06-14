/*
https://leetcode.com/problems/gray-code/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
	vector<int> ans;

	for (int i = 0; i < (1 << n); ++i) {
		ans.push_back(i ^ (i / 2));
	}

	return ans;
}

int main() {

	int n = 4;
	vector<int> res = grayCode(n);

	for (auto x : res) {
		cout << x << " ";
	}
	cout << endl;
}