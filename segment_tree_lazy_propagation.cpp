#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int tree[4 * N], lazy[4 * N], arr[N];

void build(int node, int st, int nd) {
	if (st == nd) {
		tree[node] = arr[st];
		return ;
	}

	int mid = (st + nd) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int st, int nd, int l, int r, int val) {
	
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

int query(int node, int st, int nd, int l, int r) {
	if (lazy[node] != 0) {
		tree[node] += (nd - st + 1) * lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;

	if (st > r || nd < l) return 0;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;
	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);
	// cout<<tree[1]<<endl;
	update(1, 0, n - 1, 1, 5, 10);
	cout << query(1, 0, n - 1, 1, 3) << endl;
	update(1, 0, n - 1, 1, 2, -1);
	cout << query(1, 0, n - 1, 1, 3) << endl;
}