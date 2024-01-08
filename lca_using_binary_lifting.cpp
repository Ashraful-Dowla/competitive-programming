/*
https://www.spoj.com/problems/LCASQ/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int LOG = 20;

int up[N][LOG], depth[N];
vector<int> tree[N];

//time complexity -> O(N);
void dfs(int v) {

	for (int child : tree[v]) {
		up[child][0] = v;
		depth[child] = depth[v] + 1;

		for (int j = 1; j < LOG; ++j) {
			up[child][j] = up[up[child][j - 1]][j - 1];
		}
		dfs(child);
	}
}

// time complexity -> O(log(N))
int get_lca(int a, int b) {

	if (depth[a] < depth[b]) {
		swap(a, b);
	}

	int k = depth[a] - depth[b];

	for (int j = 0; j < LOG; ++j) {
		if (k & (1 << j)) {
			a = up[a][j];
		}
	}

	if (a == b) {
		return a;
	}

	for (int j = LOG - 1; j >= 0; --j) {
		if (up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}

	return up[a][0];
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int v;
			cin >> v;
			tree[i].push_back(v);
		}
	}

	dfs(0);

	int q;
	cin >> q;

	while (q--) {
		int a, b;
		cin >> a >> b;

		cout << get_lca(a, b) << endl;
	}
}