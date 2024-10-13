/*
https://atcoder.jp/contests/abc372/tasks/abc372_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int m;
	cin >> m;

	vector<int> pre(12, 1);
	for (int i = 1; i < 11; ++i) {
		pre[i] = pre[i - 1] * 3;
	}

	vector<int> ans;

	for (int i = 10; i >= 0; --i) {
		int p = pre[i];
		while (m >= p) {
			ans.push_back(i);
			m -= p;
		}
		if (m == 0) {
			break;
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}