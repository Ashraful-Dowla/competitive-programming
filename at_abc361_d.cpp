/*
https://atcoder.jp/contests/abc361/tasks/abc361_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int dis[(1 << 16) + 10][16];

int main() {

	int n;
	cin >> n;

	string s, t;
	cin >> s;
	cin >> t;

	int ss = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'W') {
			ss |= (1 << i);
		}
	}

	int dd = 0;
	for (int i = 0; i < n; ++i) {
		if (t[i] == 'W') {
			dd |= (1 << i);
		}
	}

	for (int i = 0; i < (1 << (n + 2)); ++i) {
		for (int j = 0; j <= n; ++j) {
			dis[i][j] = 1e8;
		}
	}

	queue<pii> q;
	q.push({ss, n});
	dis[ss][n] = 0;

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		int ss = p.first, tt = p.second;
		int cost = dis[ss][tt];

		for (int i = 0; i <= n; ++i) {

			if (abs(i - tt) <= 1) {
				continue;
			}

			int ns = ss;
			if (ss & (1 << i)) {
				ns ^= (1 << i);
				ns |= (1 << tt);
			}

			if (ss & (1 << (i + 1))) {
				ns ^= (1 << (i + 1));
				ns |= (1 << (tt + 1));
			}

			if (cost + 1 < dis[ns][i]) {
				dis[ns][i] = cost + 1;
				q.push({ns, i});
			}
		}
	}

	cout << (dis[dd][n] == 1e8 ? -1 : dis[dd][n]) << endl;

}