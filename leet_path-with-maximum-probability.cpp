/*
https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-31
*/
#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges,
                      vector<double>& succProb, int start_node, int end_node) {

	vector<pair<int, double>> graph[n + 1];

	int i = 0;
	for (auto e : edges) {
		graph[e[0]].push_back({e[1], succProb[i]});
		graph[e[1]].push_back({e[0], succProb[i]});
		++i;
	}

	multiset<pair<double, int>> ms;
	vector<double>prob(n + 1, 0);
	vector<bool> vis(n + 1);

	prob[start_node] = 1;
	ms.insert({1, start_node});

	while (ms.size() > 0) {

		auto node = (--ms.end());
		int u = node->second;

		ms.erase(node);

		if (vis[u]) {
			continue;
		}
		vis[u] = true;

		for (auto node : graph[u]) {

			int v = node.first;
			double p = node.second;

			if (prob[u]*p > prob[v]) {
				prob[v] = prob[u] * p;
				ms.insert({prob[v], v});
			}
		}
	}

	return prob[end_node];
}

int main() {

	int n = 3;
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
	vector<double> succProb = {0.5, 0.5, 0.2};
	int start_node = 0, end_node = 2;

	cout << maxProbability(n, edges, succProb, start_node, end_node) << endl;
}