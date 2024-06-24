/*
https://atcoder.jp/contests/abc276/tasks/abc276_b
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> g[N];

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {

		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());

		cout << g[i].size();
		for (int x : g[i]) {
			cout << " " << x;
		}
		cout << endl;
	}

}