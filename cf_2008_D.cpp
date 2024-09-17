//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/2008/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 2e5 + 10;
string s;
int n, black;
vector<int> graph[N], color(N), res(N);
vector<bool> vis(N);

void dfs(int u) {

	vis[u] = true;
	if (color[u] == 0) {
		black++;
	}

	for (int v : graph[u]) {
		if (vis[v]) continue;
		dfs(v);
		res[v] = black;
	}
}

void solve() {

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];

		graph[i].push_back(v[i]);
		graph[v[i]].push_back(i);
	}

	cin >> s;

	for (int i = 1; i <= s.size(); ++i) {
		color[v[i]] = (s[i - 1] - '0');
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			black = 0;
			dfs(i);
			res[i] = black;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; ++i) {
		graph[i].clear();
		vis[i] = false;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}