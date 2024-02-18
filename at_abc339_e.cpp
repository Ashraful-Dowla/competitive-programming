/*
https://atcoder.jp/contests/abc339/tasks/abc339_e
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
int tree[4 * MX + 10];

int query(int node, int st, int nd, int l, int r) {

	if (st > r || nd < l) return -1e6;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;

	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return max(q1, q2);
}

void update(int node, int st, int nd, int idx, int val) {

	if (st == nd) {
		tree[node] = val;
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main() {

	int n, d;
	cin >> n >> d;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx_len = query(1, 1, MX, max(1, v[i] - d), min(MX, v[i] + d)) + 1;
		update(1, 1, MX, v[i], mx_len);
		ans = max(ans, mx_len);
	}
	cout << ans << endl;
}