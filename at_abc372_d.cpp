/*
https://atcoder.jp/contests/abc372/tasks/abc372_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<int> ans(n);
	stack<int> stk;
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = stk.size();
		while (!stk.empty() && stk.top() < v[i]) {
			stk.pop();
		}
		stk.push(v[i]);
	}

	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}
