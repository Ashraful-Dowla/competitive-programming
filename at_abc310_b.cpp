/*
https://atcoder.jp/contests/abc310/tasks/abc310_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool f[105][105];

bool cmp(pii a, pii b) {
	return a.first > b.first;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<pii>p(n);
	int c[n];
	vector<int> g[n];

	for (int i = 0; i < n; ++i) {
		int pp;
		cin >> pp >> c[i];

		p[i] = {pp, i};

		for (int j = 0; j < c[i]; ++j) {
			int x;
			cin >> x;
			f[i][x] = true;
			g[i].push_back(x);
		}
	}

	sort(p.begin(), p.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {

			bool ok = true;
			if (p[i].first >= p[j].first) {
				for (int k : g[p[i].second]) {
					if (f[p[j].second][k]) continue;
					ok = false;
					break;
				}
			}

			if ((p[i].first > p[j].first ||
			        g[p[i].second].size() < g[p[j].second].size()) && ok) {

				ans++;
				break;
			}
		}

		if (ans) break;
	}

	cout << (ans ? "Yes" : "No") << endl;
}