/*
https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21
*/
#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

	vector<int> graph[n];

	for (auto e : edges) {
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}

	vector<int> level(n, 1e8);

	queue<int> q;
	q.push(source);
	level[source] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (level[v] > level[u] + 1) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}

	return level[destination] != 1e8;
}

int main() {

	int n = 3;
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
	int source = 0, destination = 2;

	cout << validPath(n, edges, source, destination);
}