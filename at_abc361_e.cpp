/*
https://atcoder.jp/contests/abc361/tasks/abc361_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> graph[N];
ll depth[N];

void dfs(int v, int p) {

	for (auto child : graph[v]) {
		if (child.first == p) continue;
		depth[child.first] = depth[v] + child.second;
		dfs(child.first, v);
	}

}

int main() {

	int n;
	cin >> n;

	ll len = 0;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll c;
		cin >> u >> v >> c;

		graph[u].push_back({v, c});
		graph[v].push_back({u, c});

		len += c;
	}

	dfs(1, -1);

	ll mx_depth = 0;
	int mx_depth_node = -1;
	for (int i = 1; i <= n; ++i) {
		if (mx_depth < depth[i]) {
			mx_depth = depth[i];
			mx_depth_node = i;
		}
		depth[i] = 0;
	}

	dfs(mx_depth_node, -1);

	mx_depth = 0;
	for (int i = 1; i <= n; ++i) {
		if (mx_depth < depth[i]) {
			mx_depth = depth[i];
		}
	}

	cout << 2 * len - mx_depth << endl;
}