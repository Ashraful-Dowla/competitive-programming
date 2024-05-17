/*
https://atcoder.jp/contests/abc282/tasks/abc282_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
vector<int> graph[N], color(N, -1);
int ct[2];

bool bfs(int s) {

	queue<int> q;
	q.push(s);
	color[s] = 0;
	ct[0]++;

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				ct[color[v]]++;
				q.push(v);
			}
			else if (color[v] == color[u]) {
				return false;
			}
		}
	}

	return true;
}


int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	ll ans  = n * 1LL * (n - 1);
	ans /= 2;
	ans -= m;

	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			if (!bfs(i)) {
				cout << 0 << endl;
				return 0;
			}
			ans -= ((ct[0] * 1LL * (ct[0] - 1)) / 2);
			ans -= ((ct[1] * 1LL * (ct[1] - 1)) / 2);
			ct[0] = ct[1] = 0;
		}
	}

	cout << ans << endl;

}