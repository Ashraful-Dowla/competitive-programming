/*
https://leetcode.com/problems/combination-sum-iii/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int>temp;
bool taken[10];
map<vector<int>, bool> mp;

void solve(int n, int k, int idx) {

	if (n == 0 && k == 0) {
		vector<int> res = temp;
		sort(res.begin(), res.end());
		if (!mp[res]) {
			ans.push_back(res);
			mp[res] = true;
		}
		return;
	}


	for (int i = 9; i >= 1; --i) {
		if (taken[i]) continue;

		if (n >= i) {
			temp.push_back(i);
			taken[i] = true;
			solve(n - i, k - 1, idx + 1);

			temp.pop_back();
			taken[i] = false;
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	solve(n, k, 1);
	return ans;
}

int main() {

	// int k = 3, n = 7;
	// int k = 3, n = 9;
	int k = 4, n = 1;

	auto res = combinationSum3(k, n);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}