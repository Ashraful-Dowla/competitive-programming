/*
https://atcoder.jp/contests/abc274/tasks/abc274_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> graph[2 * n + 2];

	for (int i = 1; i <= n; ++i) {
		int u;
		cin >> u;

		graph[u].push_back(2 * i);
		graph[u].push_back(2 * i + 1);
		graph[2 * i].push_back(u);
		graph[2 * i + 1].push_back(u);

	}

	vector<int> level(2 * n + 2, 1e7);

	queue<int> q;
	q.push(1);
	level[1] = 0;

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

	for (int i = 1; i <= 2 * n + 1; ++i) {
		cout << level[i] << endl;
	}
}