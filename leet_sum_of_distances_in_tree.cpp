/*
https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> tree[30005];
vector<int> child;

int bfs(int n, int v) {

	queue<int> q;
	vector<int> level(n, 1e6);

	q.push(v);
	level[v] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int child : tree[u]) {
			if (level[child] > level[u] + 1) {
				level[child] = level[u] + 1;
				q.push(child);
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += level[i];
	}

	return sum;
}

int dfs(int v, int par) {

	for (int ch : tree[v]) {
		if (ch == par) continue;
		child[v] += dfs(ch, v);
	}

	return child[v];
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

	for (auto v : edges) {
		tree[v[0]].push_back(v[1]);
		tree[v[1]].push_back(v[0]);
	}


	child.assign(n, 1);

	vector<int> ans(n);

	ans[0] = bfs(n, 0);
	child[0] = dfs(0, -1);

	queue<int> q;
	q.push(0);
	vector<bool> vis(n, false);

	vis[0] = true;
	while (!q.empty()) {
		int par = q.front();
		q.pop();

		for (int u : tree[par]) {
			if (vis[u]) continue;
			ans[u] = ans[par] - child[u] + (n - child[u]);
			q.push(u);
			vis[u] = true;
		}
	}

	return ans;
}

int main() {

	int n = 6;
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

	auto res = sumOfDistancesInTree(n, edges);

	for (int x : res) {
		cout << x << " ";
	}
}