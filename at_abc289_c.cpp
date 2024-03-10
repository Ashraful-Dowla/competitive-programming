/*
https://atcoder.jp/contests/abc289/tasks/abc289_c
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 12;
vector<int> v(N);

int solve(int n, int m, int i, int res) {

	if (i == m) {
		return __builtin_popcount(res) == n;
	}

	int cnt = 0;
	cnt += solve(n, m, i + 1, res | v[i]);
	cnt += solve(n, m, i + 1, res);

	return cnt;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;

		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			v[i] |= (1 << x);
		}
	}

	cout << solve(n, m, 0, 0) << endl;
}