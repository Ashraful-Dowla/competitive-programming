//Author: Ashraful Dowla
/*
https://atcoder.jp/contests/abc354/tasks/abc354_f
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class SegTree {
public:

	vector<int> tree;

	SegTree(int n) {
		tree.resize(5 * n, 0);
	}

	int query(int node, int st, int nd, int l, int r) {

		if (st > r || nd < l) return 0;
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

};

void solve() {

	int n;
	cin >> n;

	vector<int> nums(n), v(n);

	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		v[i] = nums[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	SegTree st1(n);
	vector<int> pf(n);

	int lis = 0;
	for (int i = 0; i < n; ++i) {

		int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();

		pf[i] = 1 + st1.query(1, 0, v.size() - 1, 0, idx - 1);
		lis = max(lis, pf[i]);
		st1.update(1, 0, v.size() - 1, idx, pf[i]);
	}

	SegTree st2(n);
	vector<int> sf(n);

	for (int i = n - 1; i >= 0; --i) {
		int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();

		sf[i] = 1 + st2.query(1, 0, v.size() - 1, idx + 1, n - 1);
		st2.update(1, 0, v.size() - 1, idx, sf[i]);
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (pf[i] + sf[i] - 1 == lis) {
			ans.push_back(i + 1);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}