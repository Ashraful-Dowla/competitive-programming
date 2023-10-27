#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int tree[4 * N], arr[N];

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

void update(int node, int st, int nd, int idx) {
	if (st == nd) {
		arr[st] = 1 - arr[st];
		tree[node] = arr[st];
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx);
	else update(2 * node + 1, mid + 1, nd, idx);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

//descending the segment tree
int query(int node, int st, int nd, int k) {
	if (st == nd) return st;

	int mid = (st + nd) / 2;
	if (k < tree[2 * node]) {
		return query(2 * node, st, mid, k);
	}
	else {
		return query(2 * node + 1, mid + 1, nd, k - tree[2 * node]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int idx;
			cin >> idx;
			update(1, 0, n - 1, idx);
		}
		else {
			int k;
			cin >> k;
			cout << query(1, 0, n - 1, k) << endl;
		}
	}
}