/*
https://atcoder.jp/contests/abc370/tasks/abc370_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {


	int n, m, q;
	cin >> n >> m >> q;

	map<int, set<int>> row, col;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			row[i].insert(j);
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			col[i].insert(j);
		}
	}

	int ans = n * m;
	while (q--) {
		int x, y;
		cin >> x >> y;

		if (row[x].find(y) != row[x].end()
		        && col[y].find(x) != col[y].end()) {
			row[x].erase(y);
			col[y].erase(x);
			ans--;
		}
		else {

			auto t = row[x].upper_bound(y);
			auto it = t;
			auto it2 = --t;

			if (*it >= 1 && *it <= m) {
				col[*it].erase(x);
				row[x].erase(it);
				ans--;
			}
			if (*it2 >= 1 && *it2 <= m) {
				col[*it2].erase(x);
				row[x].erase(it2);
				ans--;
			}

			auto tt = col[y].upper_bound(x);
			auto it3 = tt;
			auto it4 = --tt;

			if (*it3 >= 1 && *it3 <= n) {
				row[*it3].erase(y);
				col[y].erase(it3);
				ans--;
			}
			if (*it4 >= 1 && *it4 <= n) {
				row[*it4].erase(y);
				col[y].erase(it4);
				ans--;
			}
		}
	}

	cout << ans << endl;
}