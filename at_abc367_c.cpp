/*
https://atcoder.jp/contests/abc367/tasks/abc367_c
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, r[10];
vector<int> t;
vector<vector<int>> ans;

void solve(int i) {

	if (i == n) {
		int sum = accumulate(t.begin(), t.end(), 0);
		if (sum % k == 0) {
			ans.push_back(t);
		}
		return ;
	}

	for (int j = 1; j <= r[i]; ++j) {
		t.push_back(j);
		solve(i + 1);
		t.pop_back();
	}
}

int main() {

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}

	solve(0);

	for (auto v : ans) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}