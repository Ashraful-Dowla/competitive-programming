/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29
*/
#include <bits/stdc++.h>
using namespace std;

int par[100005], n, m, sz[100005], st[1005][1005];

void make() {
	for (int i = 0; i < n + m; ++i) {
		par[i] = i;
		sz[i] = 1;
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

int removeStones(vector<vector<int>>& stones) {

	vector<int> row, col;
	for (auto s : stones) {
		row.push_back(s[0]);
		col.push_back(s[1]);
	}

	sort(row.begin(), row.end());
	row.erase(unique(row.begin(), row.end()), row.end());

	sort(col.begin(), col.end());
	col.erase(unique(col.begin(), col.end()), col.end());

	n = row.size(), m = col.size();

	for (auto s : stones) {
		int r = lower_bound(row.begin(), row.end(), s[0]) - row.begin();
		int c = lower_bound(col.begin(), col.end(), s[1]) - col.begin();
		st[r][c]++;
	}

	make();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (st[i][j]) {
				Union(i, n + j);
			}
		}
	}

	set<int> root;
	for (int i = 0; i < n + m; ++i) {
		root.insert(find(i));
	}

	return stones.size() - root.size();;
}

int main() {

	// vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
	// vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
	// vector<vector<int>> stones = {{0, 0}};
	vector<vector<int>> stones = {{0, 1}, {1, 0}, {1, 1}};

	cout << removeStones(stones) << endl;
}