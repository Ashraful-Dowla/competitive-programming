/*
https://atcoder.jp/contests/abc333/tasks/abc333_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
vector<int> graph[N];
vector<bool> vis(N), taken(N);
int cnt;

void dfs(int v) {

	vis[v] = true;
	cnt++;

	for (int x : graph[v]) {
		if (vis[x]) {
			continue;
		}
		dfs(x);
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vis[1] = true;

	for (int x : graph[1]) {
		vis[x] = true;
	}

	vector<int> height;

	for (int x : graph[1]) {

		if (taken[x]) {
			continue;
		}

		cnt = 0;
		vis[x] = false;
		dfs(x);
		vis[x] = true;
		height.push_back(cnt);

		taken[x] = true;
	}


	sort(height.begin(), height.end());

	int ans = 1;
	for (int i = 0; i < height.size() - 1; ++i) {
		ans += height[i];
	}

	cout << ans << endl;
}