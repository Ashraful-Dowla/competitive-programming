/*
https://atcoder.jp/contests/abc371/tasks/abc371_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
ll tree[4 * N];

void update(int node, int st, int nd, int idx, ll val) {

	if (st == nd) {
		tree[node] = val;
		return ;
	}

	int mid = (st + nd) / 2;

	if (idx <= mid) {
		update(2 * node, st, mid, idx, val);
	}
	else {
		update(2 * node + 1, mid + 1, nd, idx, val);
	}

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int st, int nd, int l, int r) {

	if (l > nd || r < st) {
		return 0;
	}
	if (l <= st && nd <= r) {
		return tree[node];
	}

	int mid = (st + nd) / 2;

	ll q1 = query(2 * node, st, mid, l, r);
	ll q2 = query(2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

int main() {

	int n;
	cin >> n;

	vector<ll> x(n), p(n);

	vector<ll> v;

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		v.push_back(x[i]);
	}

	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	int q;
	cin >> q;

	vector<int> l(q), r(q);
	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];

		v.push_back(l[i]);
		v.push_back(r[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
		update(1, 0, N - 1, idx, p[i]);
	}

	for (int i = 0; i < q; ++i) {

		int ldx = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		int rdx = lower_bound(v.begin(), v.end(), r[i]) - v.begin();

		cout << query(1, 0, N - 1, ldx, rdx) << endl;
	}
}