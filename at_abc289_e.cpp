/*
https://atcoder.jp/contests/abc289/tasks/abc289_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
	int t, a;
	ll d;
};

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> graph[n + 1], color(n + 1);
		vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, 0));

		for (int i = 1; i <= n; ++i) {
			cin >> color[i];
		}

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		queue<node> q;
		q.push({1, n, 0});

		ll ans = -1;
		while (!q.empty()) {
			node p = q.front();
			q.pop();

			int t = p.t, a = p.a;
			ll d = p.d;

			if (t == n && a == 1) {
				ans = d;
				break;
			}

			for (int tt : graph[t]) {
				for (int aa : graph[a]) {
					if (color[tt] != color[aa] && !vis[tt][aa]) {
						vis[tt][aa] = true;
						q.push({tt, aa, d + 1});
					}
				}
			}
		}

		cout << ans << endl;
	}

}