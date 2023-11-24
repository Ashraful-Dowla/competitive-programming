/*
https://atcoder.jp/contests/abc315/tasks/abc315_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N], ans;
vector<bool> vis(N);

void dfs(int v) {

	vis[v] = true;
	for (int child : graph[v]) {
		if (vis[child]) continue;
		dfs(child);
		ans.push_back(child);
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			graph[i].push_back(x);
		}
	}

	dfs(1);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}