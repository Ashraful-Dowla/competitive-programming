/*
https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30
*/
#include <bits/stdc++.h>
using namespace std;

struct DisjoinSet {

	vector<int> sz, par;
	DisjoinSet(int n) {
		sz.resize(n + 5);
		par.resize(n + 5);
	}

	void make(int n) {
		for (int i = 1; i <= n; ++i) {
			sz[i] = 1;
			par[i] = i;
		}
	}

	int find(int v) {
		if (v == par[v]) return v;
		return par[v] = find(par[v]);
	}

	void Union(int a, int b) {

		a = find(a);
		b = find(b);

		if (a != b) {
			if (sz[a] < sz[b]) {
				swap(a, b);
			}

			par[b] = a;
			sz[a] += sz[b];
		}
	}
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

	DisjoinSet alice(n), bob(n);

	alice.make(n);
	bob.make(n);

	int ans = 0;
	for (auto edge : edges) {
		if (edge[0] == 3) {

			bool ok = false;
			if (alice.find(edge[1]) != alice.find(edge[2])) {
				alice.Union(edge[1], edge[2]);
			}
			else ok = true;

			if (bob.find(edge[1]) != bob.find(edge[2])) {
				bob.Union(edge[1], edge[2]);
			}
			else ok = true;

			if (ok) ans++;
		}
	}

	for (auto edge : edges) {
		if (edge[0] == 3) continue;

		if (edge[0] == 1) {
			if (alice.find(edge[1]) == alice.find(edge[2])) {
				ans++;
				continue;
			}

			alice.Union(edge[1], edge[2]);
		}
		else {
			if (bob.find(edge[1]) == bob.find(edge[2])) {
				ans++;
				continue;
			}
			bob.Union(edge[1], edge[2]);
		}
	}

	if (alice.sz[alice.find(1)] == n && bob.sz[bob.find(1)] == n) {
		return ans;
	}

	return -1;
}

int main() {

	int n = 4;
	vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
		{1, 2, 4}, {1, 1, 2}, {2, 3, 4}
	};

	// int n = 4;
	// vector<vector<int>> edges = {{3, 2, 3}, {1, 1, 2}, {2, 3, 4}};

	cout << maxNumEdgesToRemove(n, edges);
}