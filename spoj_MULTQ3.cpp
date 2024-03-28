/*
https://www.spoj.com/problems/MULTQ3/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int tree[4 * N][3], lazy[4 * N];

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node][0] = 1;
		return ;
	}

	int mid = (st + nd) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node][0] = tree[2 * node][0] + tree[2 * node + 1][0];
}

void swap1(int &a, int &b, int &c) {

	int ta = a, tb = b, tc = c;

	a = tc;
	b = ta;
	c = tb;
}

void swap2(int &a, int &b, int &c) {

	int ta = a, tb = b, tc = c;

	a = tb;
	b = tc;
	c = ta;
}

void propagate(int node, int st, int nd) {

	if (st != nd) {
		lazy[2 * node] = (lazy[2 * node] + lazy[node]) % 3;
		lazy[2 * node + 1] = (lazy[2 * node + 1] + lazy[node]) % 3;
	}

	if (lazy[node] == 1) {
		swap1(tree[node][0], tree[node][1], tree[node][2]);
	}
	if (lazy[node] == 2) {
		swap2(tree[node][0], tree[node][1], tree[node][2]);
	}
}

void update(int node, int st, int nd, int l, int r) {

	if (lazy[node] != 0) {
		propagate(node, st, nd);
	}
	lazy[node] = 0;

	if (st > r || nd < l) return ;
	if (l <= st && nd <= r) {
		if (st != nd) {
			lazy[2 * node] = (lazy[2 * node] + 1) % 3;
			lazy[2 * node + 1] = (lazy[2 * node + 1] + 1) % 3;
		}
		swap1(tree[node][0], tree[node][1], tree[node][2]);
		return ;
	}


	int mid = (st + nd) / 2;

	update(2 * node, st, mid, l, r);
	update(2 * node + 1, mid + 1, nd, l, r);

	for (int i = 0; i < 3; ++i) {
		tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
	}
}

int query(int node, int st, int nd, int l, int r) {

	if (lazy[node] != 0) {
		propagate(node, st, nd);
	}
	lazy[node] = 0;

	if (st > r || nd < l) return 0;
	if (l <= st && nd <= r) {
		return tree[node][0];
	}

	int mid = (st + nd) / 2;
	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

int main() {
	int n, q;
	cin >> n >> q;

	build(1, 0, n - 1);

	while (q--) {

		int t, l, r;
		cin >> t >> l >> r;

		if (t == 0) {
			update(1, 0, n - 1, l, r);
		}
		else {
			cout << query(1, 0, n - 1, l, r) << endl;
		}
	}
}