/*
https://atcoder.jp/contests/abc322/tasks/abc322_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	unordered_map<int, bool> mp;

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		mp[x] = true;
	}

	int ans[n + 1];

	int top;

	for (int i = n; i >= 1; --i) {

		if (mp[i]) {
			top = i;
			ans[i] = 0;
		}
		else {
			ans[i] = top - i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
}