/*
https://atcoder.jp/contests/abc311/tasks/abc311_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<bool> taken(n + 1, false);
	vector<int> res, ans;

	int u = 1;
	while (!taken[u]) {
		taken[u] = true;
		res.push_back(u);
		u = v[u];
	}

	for (int x : res) {
		if (x == u) u = -1;
		if (u == -1) {
			ans.push_back(x);
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}