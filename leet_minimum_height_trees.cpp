/*
https://leetcode.com/problems/minimum-height-trees/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

	vector<int> graph[20005], degree(n, 0), ans;

	if (n <= 2) {
		for (int i = 0; i < n; ++i) {
			ans.push_back(i);
		}
		return ans;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u = edges[i][0], v = edges[i][1];

		graph[u].push_back(v);
		graph[v].push_back(u);

		degree[u]++;
		degree[v]++;

	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (degree[i] == 1) {
			q.push(i);
		}
	}

	int nodes = n;

	while (nodes > 2) {

		int sz = q.size();
		nodes -= sz;

		while (sz--) {
			int v = q.front();
			q.pop();

			for (int child : graph[v]) {
				degree[child]--;
				if (degree[child] == 1) {
					q.push(child);
				}
			}
		}
	}

	while (!q.empty()) {
		ans.push_back(q.front());
		q.pop();
	}

	return ans;
}

int main() {

	// int n = 4;
	// vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

	// int n = 6;
	// vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};

	int n = 2;
	vector<vector<int>> edges = {{1, 0}};
	auto res = findMinHeightTrees(n, edges);

	for (int v : res) {
		cout << v << " ";
	}
}