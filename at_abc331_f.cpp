/*
https://atcoder.jp/contests/abc331/tasks/abc331_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const ll prime = 31;
const ll M = 998244353;

ll power(ll a, ll b) {

	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}

	return res;
}

void build(vector<ll>& tree, vector<ll>& hsh, int node, int st, int nd) {

	if (st == nd) {
		tree[node] = hsh[st];
		return;
	}

	int mid = (st + nd) / 2;
	build(tree, hsh, 2 * node, st, mid);
	build(tree, hsh, 2 * node + 1, mid + 1, nd);

	tree[node] = tree[2 * node] + tree[2 * node + 1];

}

ll query(vector<ll>& tree, int node, int st, int nd, int l, int r) {

	if (st > r || nd < l) return 0;
	if (l <= st && nd <= r) {
		return tree[node];
	}

	int mid = (st + nd) / 2;
	ll q1 = query(tree, 2 * node, st, mid, l, r);
	ll q2 = query(tree, 2 * node + 1, mid + 1, nd, l, r);

	return q1 + q2;
}

void update(vector<ll>& tree, vector<ll>& hsh, int node, int st, int nd, int idx, ll val) {

	if (st == nd) {
		tree[node] = hsh[st] = val;
		return;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(tree, hsh, 2 * node, st, mid, idx, val);
	else update(tree, hsh, 2 * node + 1, mid + 1, nd, idx, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];

}

int main() {

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<ll> tree_pf(4 * N, 0), tree_sf(4 * N, 0), hsh_pf(N), hsh_sf(N);

	for (int i = 0; i < n; ++i) {
		hsh_pf[i] = power(prime, i) * (s[i] - 'a' + 1);
		hsh_pf[i] %= M;

		hsh_sf[i] = power(prime, n - i - 1) * (s[i] - 'a' + 1);
		hsh_sf[i] %= M;
	}

	build(tree_pf, hsh_pf, 1, 0, n - 1);
	build(tree_sf, hsh_sf, 1, 0, n - 1);

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int idx;
			char c;
			cin >> idx >> c;

			idx--;

			ll hsh1 = power(prime, idx) * (c - 'a' + 1);
			hsh1 %= M;

			ll hsh2 = power(prime, n - idx - 1) * (c - 'a' + 1);
			hsh2 %= M;

			update(tree_pf, hsh_pf, 1, 0, n - 1, idx, hsh1);
			update(tree_sf, hsh_sf, 1, 0, n - 1, idx, hsh2);
		}
		else {
			int l, r;
			cin >> l >> r;

			l--, r--;

			ll q1 = query(tree_pf, 1, 0, n - 1, l, r);
			ll q2 = query(tree_sf, 1, 0, n - 1, l, r);

			q1 = (q1 % M * power(power(prime, l), M - 2)) % M;
			q2 = (q2 % M * power(power(prime, n - r - 1), M - 2)) % M;

			// cout << q1 << " " << q2 << endl;

			if (q1 == q2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}