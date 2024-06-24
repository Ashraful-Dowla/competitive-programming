/*
https://atcoder.jp/contests/abc357/tasks/abc357_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

vector<int> graph[N], rev[N], par(N), sz(N), res(N, 1), vec;
bool vis[N], vis2[N];
stack<int> stk;

void make() {
	for (int i = 1; i < N; ++i) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		par[b] = a;
		sz[a] += sz[b];
	}
}

void dfs(int u) {

	vis[u] = true;
	for (int v : graph[u]) {
		if (vis[v]) continue;
		dfs(v);
	}

	stk.push(u);
	vec.push_back(u);
}

void dfs2(int u) {

	vis2[u] = true;
	for (int v : rev[u]) {
		if (vis2[v]) continue;
		dfs2(v);
		Union(u, v);
	}
}


int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		graph[i].push_back(v);
		rev[v].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		dfs(i);
	}

	make();

	while (!stk.empty()) {
		if (!vis2[stk.top()]) {
			dfs2(stk.top());
		}
		stk.pop();
	}

	for (int u : vec) {
		for (int v : graph[u]) {
			if (find(u) == find(v)) {
				res[u] = sz[find(v)];
			}
			else {
				res[u] += res[v];
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += res[i];
	}

	cout << ans << endl;
}