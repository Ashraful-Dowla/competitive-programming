/*
https://atcoder.jp/contests/abc299/tasks/abc299_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m, k, p[N], d[N], dis[N][N];
vector<int> graph[N];
vector<bool> black(N, true);

void bfs(int s, int d) {

	dis[s][s] = 0;
	queue<int> q;

	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int child : graph[v]) {
			if (dis[s][child] < 0) {
				dis[s][child] = dis[s][v] + 1;
				q.push(child);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dis[s][i] < d) {
			black[i] = false;
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = -1;
		}
	}

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> p[i] >> d[i];
		bfs(p[i], d[i]);
	}

	string ans;
	bool chk = false;
	for (int i = 1; i <= n; ++i) {
		if (black[i]) {
			chk = true;
			ans.push_back('1');
		}
		else {
			ans.push_back('0');
		}
	}

	if (!chk) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < k; ++i) {

		int min_dis = 1e9;
		for (int j = 1; j <= n; ++j) {
			if (black[j]) {
				min_dis = min(min_dis, dis[p[i]][j]);
			}
		}

		if (min_dis != d[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	cout << ans << endl;

}