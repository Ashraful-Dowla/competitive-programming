#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, UNVISITED = -1;
bool visited[N];
int dfs_low[N], dfs_num[N];
int num_cnt, num_scc;
vector<int> store, graph[N];

void dfs(int v) {
	
	dfs_low[v] = dfs_num[v] = num_cnt++;
	store.push_back(v);
	visited[v] = true;

	for (int child : graph[v]) {
		if (dfs_num[child] == UNVISITED) {
			dfs(child);
		}
		if (visited[child]) {
			dfs_low[v] = min(dfs_low[v], dfs_low[child]);
		}
	}

	if (dfs_low[v] == dfs_num[v]) {
		++num_scc;
		while (true) {
			int nd = store.back();
			store.pop_back();
			visited[nd] = false;
			cout << nd << " ";
			if (v == nd) break;
		}
		cout << endl;
	}
}

int main() {
	int n, num;
	cin >> num;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	memset(visited, false, sizeof(visited));
	memset(dfs_num, UNVISITED, sizeof(dfs_num));

	for (int i = 0; i < num; ++i) {
		if (dfs_num[i] == UNVISITED) {
			dfs(i);
		}
	}
	cout << "----" << endl;
	cout << num_scc << endl;
}