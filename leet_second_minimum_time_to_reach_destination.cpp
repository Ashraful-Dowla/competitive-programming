/*
https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/?envType=daily-question&envId=2024-07-28
*/
#include <bits/stdc++.h>
using namespace std;

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

	vector<int> graph[n + 1], vis[n + 1];
	for (auto e : edges) {
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}

	vector<int> dis1(n + 1, -1), dis2(n + 1, -1);

	queue<pair<int, int>> q;
	q.push({1, 1});
	dis1[1] = 0;

	while (!q.empty()) {

		auto p = q.front();
		q.pop();
		int u = p.first, fq = p.second;

		int curr_time = fq == 1 ? dis1[u] : dis2[u];

		if ((curr_time / change) % 2 == 1) {
			curr_time += change - (curr_time % change);
		}
		curr_time += time;

		for (int v : graph[u]) {
			if (dis1[v] == -1) {
				dis1[v] = curr_time;
				q.push({v, 1});
			}
			else if (dis2[v] == -1 && dis1[v] != curr_time) {
				if (v == n) {
					return curr_time;
				}
				dis2[v] = curr_time;
				q.push({v, 2});
			}
		}
	}

	return 0;
}

int main() {

	int n = 5;
	vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
	int time = 3;
	int change = 5;

	cout << secondMinimum(n, edges, time, change) << endl;
}