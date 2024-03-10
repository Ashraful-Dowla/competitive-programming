/*
https://atcoder.jp/contests/abc343/tasks/abc343_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> pii;

struct T
{
	int mx, cnt_mx, sec_mx, cnt_sec_mx;
};

int a[N];
T tree[4 * N];

void resolve(map<int, int>&mp, int node) {
	mp[tree[node].mx] += tree[node].cnt_mx;
	mp[tree[node].sec_mx] += tree[node].cnt_sec_mx;
}

T solve(map<int, int>& mp) {

	auto it = (--mp.end());
	int mx = it->first, cnt_mx = it->second;

	--it;
	int sec_mx = it->first, cnt_sec_mx = it->second;

	return {mx, cnt_mx, sec_mx, cnt_sec_mx};
}

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = {a[st], 1, 0, 0};
		return ;
	}

	int mid = (st + nd) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	map<int, int> mp;

	resolve(mp, 2 * node);
	resolve(mp, 2 * node + 1);

	tree[node] = solve(mp);
}

void update(int node, int st, int nd, int idx, int val) {

	if (st == nd) {
		a[st] = val;
		tree[node] = {a[st], 1, 0, 0};
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	map<int, int> mp;

	resolve(mp, 2 * node);
	resolve(mp, 2 * node + 1);

	tree[node] = solve(mp);
}

T query(int node, int st, int nd, int l, int r) {

	if (st > r || nd < l) return {0, 0, 0, 0};
	if (l <= st && nd <= r) return tree[node];

	int mid = (st + nd) / 2;
	T q1 = query(2 * node, st, mid, l, r);
	T q2 = query(2 * node + 1, mid + 1, nd, l, r);

	map<int, int> mp;

	mp[q1.mx] += q1.cnt_mx;
	mp[q1.sec_mx] += q1.cnt_sec_mx;

	mp[q2.mx] += q2.cnt_mx;
	mp[q2.sec_mx] += q2.cnt_sec_mx;

	return solve(mp);
}

int main() {

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	build(1, 0, n - 1);

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int p, x;
			cin >> p >> x;
			--p;

			update(1, 0, n - 1, p, x);
		}
		else {
			int l, r;
			cin >> l >> r;

			--l, --r;

			T ans = query(1, 0, n - 1, l, r);

			if (ans.sec_mx == 0) cout << 0 << endl;
			else cout << ans.cnt_sec_mx << endl;
		}
	}
}