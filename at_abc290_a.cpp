/*
https://atcoder.jp/contests/abc290/tasks/abc290_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		ans += v[x - 1];
	}

	cout << ans << endl;
}