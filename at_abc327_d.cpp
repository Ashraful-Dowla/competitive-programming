/*
https://atcoder.jp/contests/abc327/tasks/abc327_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];
vector<int> vis(N, -1);
bool ok = true;

void dfs(int v, int x) {

	vis[v] = x;

	for (int child : graph[v]) {

		if (vis[child] == -1) {
			dfs(child, 1 - x);
		}
		else if (vis[v] == vis[child]) {
			ok = false;
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> a(m), b(m);

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < m; ++i) {
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i] == -1) {
			dfs(i, 0);
		}
	}

	cout << (ok ? "Yes" : "No") << endl;
}