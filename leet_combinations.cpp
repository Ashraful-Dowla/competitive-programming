/*
https://leetcode.com/problems/combinations/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(int n, int idx, int k) {

	if (k == 0) {
		ans.push_back(temp);
		return ;
	}

	if (idx <= n) {

		temp.push_back(idx);
		solve(n, idx + 1, k - 1);
		temp.pop_back();

		solve(n, idx + 1, k);
	}

}

vector<vector<int>> combine(int n, int k) {
	solve(n, 1, k);
	return ans;
}

int main() {
	int n = 3, k = 2;

	auto res = combine(n, k);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}

}