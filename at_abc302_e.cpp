/*
https://atcoder.jp/contests/abc302/tasks/abc302_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<set<int>> graph(n + 2);

	int ans = n;

	while (q--) {

		int t;
		cin >> t;

		if (t == 1) {
			int u, v;
			cin >> u >> v;

			if (graph[u].size() == 0) ans--;
			if (graph[v].size() == 0) ans--;

			graph[u].insert(v);
			graph[v].insert(u);
		}
		else {
			int v;
			cin >> v;

			for (int u : graph[v]) {

				graph[u].erase(v);

				if (graph[u].size() == 0) {
					ans++;
				}
			}

			if (graph[v].size()) {
				graph[v].clear();
				ans++;
			}
		}

		cout << ans << endl;
	}
}