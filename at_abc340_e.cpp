/*
https://atcoder.jp/contests/abc340/tasks/abc340_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
ll tree[4 * N], lazy[4 * N], a[N], b[N];

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = a[st];
		return ;
	}

	int mid = (st + nd) / 2;

	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int st, int nd, int l, int r) {

	if (lazy[node] != 0) {
		tree[node] += (nd - st + 1) * lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;

	if (st > r || nd < l) return 0;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;

	ll q1 = query(2 * node, st, mid, l, r);
	ll q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

void update(int node, int st, int nd, int l, int r, ll val) {

	if (lazy[node] != 0) {
		tree[node] += (nd - st + 1) * lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;

	if (st > r || nd < l) return ;
	if (l <= st && nd <= r) {
		tree[node] += (nd - st + 1) * val;
		if (st != nd) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return ;
	}

	int mid = (st + nd) / 2;

	update(2 * node, st, mid, l, r, val);
	update(2 * node + 1, mid + 1, nd, l, r, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	build(1, 0, n - 1);

	for (int i = 0; i < m; ++i) {

		ll x = query(1, 0, n - 1, b[i], b[i]);

		update(1, 0, n - 1, b[i], b[i], -x);
		update(1, 0, n - 1, 0, n - 1, x / n);

		if (x % n) {

			ll l = (b[i] + 1) % n, r = (l + x % n - 1) % n;

			if (l <= r) {
				update(1, 0, n - 1, l, r, 1);
			}
			else {
				update(1, 0, n - 1, l, n - 1, 1);
				update(1, 0, n - 1, 0, r, 1);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << query(1, 0, n - 1, i, i) << " ";
	}
	cout << endl;
}