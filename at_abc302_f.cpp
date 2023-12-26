/*
https://atcoder.jp/contests/abc302/tasks/abc302_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> graph[N];
vector<int> level(N, INT_MAX);

void bfs(int v) {

	queue<int> q;
	level[v] = 0;
	q.push(v);

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		for (int child : graph[u]) {
			if (level[child] > level[u] + 1) {
				level[child] = level[u] + 1;
				q.push(child);
			}
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;


	for (int i = 1, k = m + 1; i <= n; ++i, ++k) {
		int a;
		cin >> a;

		for (int j = 0; j < a; ++j) {
			int x;
			cin >> x;
			graph[k].push_back(x);
			graph[x].push_back(k);
		}
	}

	bfs(1);

	if (level[m] == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << level[m] / 2 - 1 << endl;
	}
}