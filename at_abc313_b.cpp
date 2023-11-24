/*
https://atcoder.jp/contests/abc313/tasks/abc313_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> deg(n + 2);

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;

		deg[y]++;
	}

	int ans = -1;

	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			if (ans != -1) {
				cout << -1 << endl;
				return 0;
			}
			else {
				ans = i;
			}
		}
	}

	cout << ans << endl;
}