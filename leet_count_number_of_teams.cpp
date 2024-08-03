/*
https://leetcode.com/problems/count-number-of-teams/description/
*/
#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
	vector<int> tree;
	SegTree(int sz) {
		tree.resize(4 * sz, 0);
	}

	void update(int node, int st, int nd, int idx, int val) {

		if (st == nd) {
			tree[node] = val;
			return ;
		}

		int mid = (st + nd) / 2;
		if (idx <= mid) update(2 * node, st, mid, idx, val);
		else update(2 * node + 1, mid + 1, nd, idx, val);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}

	int query(int node, int st, int nd, int l, int r) {

		if (st > r || nd < l) {
			return 0;
		}
		if (l <= st && nd <= r) {
			return tree[node];
		}

		int mid = (st + nd) / 2;
		int q1 = query(2 * node, st, mid, l, r);
		int q2 = query(2 * node + 1, mid + 1, nd, l, r);

		return q1 + q2;
	}
};

int numTeams(vector<int>& rating) {

	int n = rating.size(), N = 100005;

	SegTree pf(N), sf(N);

	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (rating[j] > rating[i]) {
				ans += sf.query(1, 0, N - 1, 0, rating[i] - 1);
			}
			if (rating[j] < rating[i]) {
				ans += pf.query(1, 0, N - 1, rating[i] + 1, N);
			}
		}
		sf.update(1, 0, N - 1, rating[i], 1);
		pf.update(1, 0, N - 1, rating[i], 1);
	}

	return ans;
}

int main() {

	// vector<int> rating = {2, 5, 3, 4, 1};
	// vector<int> rating = {2, 1, 3};
	vector<int> rating = {1, 2, 3, 4};
	cout << numTeams(rating) << endl;
}