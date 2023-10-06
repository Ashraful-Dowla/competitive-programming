#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, MOD = 1e9 + 7;
int tree[4 * N];

struct triplet
{
	int l, r, idx;
};

bool comp(triplet t1, triplet t2) {
	return t1.r < t2.r;
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
		tree[node] = val;
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
	int n;
	cin >> n;
	triplet t1;
	t1.l = -1;
	t1.r = -1;
	vector<triplet>t(n, t1);

	for (int i = 0; i < 2 * n; ++i) {
		int x;
		cin >> x;

		if (t[x - 1].l == -1) t[x - 1].l = i;
		else t[x - 1].r = i;

		t[x - 1].idx = x - 1;
	}

	sort(t.begin(), t.end(), comp);

	vector<int>ans(n);
	for (int i = 0; i < n; ++i) {
		ans[t[i].idx] = query(1, 0, 2 * n - 1, t[i].l, t[i].r);
		update(1, 0, 2 * n - 1, t[i].l, 1);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
}