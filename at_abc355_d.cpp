/*
https://atcoder.jp/contests/abc355/tasks/abc355_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegTree {
public:
	vector<ll> tree;
	SegTree(int n) {
		tree.resize(4 * n);
	}

	ll query(int node, int st, int nd, int l, int r) {

		if (st > r || nd < l) return 0;
		if (l <= st && nd <= r) return tree[node];

		int mid = (st + nd) / 2;
		ll q1 = query(2 * node, st, mid, l, r);
		ll q2 = query(2 * node + 1, mid + 1, nd, l, r);

		return q1 + q2;
	}

	void update(int node, int st, int nd, int idx, int val) {

		if (st == nd) {
			tree[node] += val;
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
};

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	vector<int> el;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		v.push_back({x, y});

		el.push_back(x);
		el.push_back(y);
	}

	el.push_back(0);

	sort(el.begin(), el.end());
	el.erase(unique(el.begin(), el.end()), el.end());

	int sz = el.size();

	SegTree left(sz), right(sz);

	for (int i = 0; i < n; ++i) {

		int l = lower_bound(el.begin(), el.end(), v[i].first) - el.begin();
		int r = lower_bound(el.begin(), el.end(), v[i].second) - el.begin();

		left.update(1, 1, sz, l, 1);
		right.update(1, 1, sz, r, 1);
	}

	ll ans = (n * 1LL * (n - 1)) / 2;
	ll res = 0;
	for (int i = 0; i < n; ++i) {

		int l = lower_bound(el.begin(), el.end(), v[i].first) - el.begin();
		int r = lower_bound(el.begin(), el.end(), v[i].second) - el.begin();

		res += right.query(1, 1, sz, 1, l - 1) + left.query(1, 1, sz, r + 1, sz);
	}

	cout << ans - (res / 2) << endl;
}