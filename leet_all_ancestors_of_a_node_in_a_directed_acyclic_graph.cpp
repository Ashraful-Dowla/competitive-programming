#include <bits/stdc++.h>
using namespace std;

vector<int> tp, graph[2000];
vector<bool> vis;
bool taken[2000][2000];

void top_sort(int v) {

	vis[v] = true;

	for (int u : graph[v]) {
		if (vis[u]) continue;
		top_sort(u);
	}

	tp.push_back(v);
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

	vis.assign(n, false);

	for (auto edge : edges) {
		graph[edge[0]].push_back(edge[1]);
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		top_sort(i);
	}

	vector<vector<int>> ans(n, vector<int>());

	for (int i = tp.size() - 1; i >= 0; --i) {
		int par = tp[i];
		for (int child : graph[par]) {

			if (!taken[child][par]) {
				ans[child].push_back(par);
				taken[child][par] = true;
			}
			for (int x : ans[par]) {
				if (!taken[child][x]) {
					ans[child].push_back(x);
					taken[child][x] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		sort(ans[i].begin(), ans[i].end());
	}

	return ans;
}

int main() {

	int n = 8;
	vector<vector<int>> edgeList = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};

	auto ans = getAncestors(n, edgeList);

	for (auto v : ans) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}