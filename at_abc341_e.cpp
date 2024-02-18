/*
https://atcoder.jp/contests/abc341/tasks/abc341_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int tree[4 * N], a[N];

void bulid(int node, int l, int r) {

	if (l == r) {
		tree[node] = a[l];
		return ;
	}

	int mid = (l + r) / 2;
	bulid(2 * node, l, mid);
	bulid(2 * node + 1, mid + 1, r);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int nd, int l, int r) {

	if (st > r || nd < l) return 0;
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;

	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

void update(int node, int st, int nd, int idx, int val) {

	if (st == nd) {
		tree[node] = a[st] = val;
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	for (int i = 0; i + 1 < n; ++i) {
		a[i + 1] = (s[i] != s[i + 1]);
	}

	if (n > 1) {
		bulid(1, 1, n - 1);
	}

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;

		if (t == 1) {
			if (l > 1) {
				update(1, 1, n - 1, l - 1, 1 - a[l - 1]);
			}
			if (r < n) {
				update(1, 1, n - 1, r, 1 - a[r]);
			}
		}
		else {
			if (l == r || query(1, 1, n - 1, l, r - 1) == (r - l)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}