#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> tree[N];
int sz[N], n;

// time complexity -> O(N)
int dfs(int u, int p) {

	sz[u] = 1;

	for (int v : tree[u]) {
		if (v != p) {
			sz[u] += dfs(v, u);
		}
	}

	return sz[u];

}

int centroid(int u, int p) {

	for (int v : tree[u]) {
		if (v != p && sz[v] > n / 2) {
			return centroid(v, u);
		}
	}

	return u;
}

int main() {

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	cout << centroid(1, 0) << endl;
}



// 11
// 1 2
// 1 3
// 3 6
// 3 7
// 2 4
// 2 5
// 5 9
// 4 8
// 8 11
// 8 10
