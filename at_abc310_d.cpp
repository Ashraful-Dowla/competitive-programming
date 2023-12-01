/*
https://atcoder.jp/contests/abc310/tasks/abc310_d
*/
#include <bits/stdc++.h>
using namespace std;

int a[50], b[50], n, t, m, team[15], ans;

void solve(int k, int t_cnt) {

	if (k == n + 1) {
		if (t != t_cnt) {
			return;
		}
		for (int i = 0; i < m; ++i) {
			if (team[a[i]] == team[b[i]]) {
				return ;
			}
		}
		ans++;
		return;
	}

	if (n - k + 1 < t - t_cnt) {
		return ;
	}

	for (int i = 1; i <= t_cnt; ++i) {
		team[k] = i;
		solve(k + 1, t_cnt);
		team[k] = 0;
	}

	if (t_cnt + 1 <= t) {
		team[k] = t_cnt + 1;
		solve(k + 1, t_cnt + 1);
		team[k] = 0;
	}
}

int main() {

	cin >> n >> t >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
	}

	solve(1, 0);
	cout << ans << endl;
}