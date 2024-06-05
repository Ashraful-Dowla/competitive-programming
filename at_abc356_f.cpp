/*
https://atcoder.jp/contests/abc356/tasks/abc356_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 3e18;
const int N = 1e6 + 10;

ll tree[4 * N], k;
vector<ll> b;
set<ll> s, h;

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

void add(ll x) {

	int idx = lower_bound(b.begin(), b.end(), x) - b.begin();
	update(1, 1, b.size(), idx, 1);

	auto it = s.upper_bound(x);
	auto jt = it;
	--it;

	ll l = *it, r = *jt;
	if (h.find(r) != h.end() && r - x <= k) {
		h.erase(r);
	}
	if (x - l > k) {
		h.insert(x);
	}
	s.insert(x);
}

void remov(ll x) {

	int idx = lower_bound(b.begin(), b.end(), x) - b.begin();
	update(1, 1, b.size(), idx, -1);

	s.erase(x);
	if (h.find(x) != h.end()) {
		h.erase(x);
	}

	auto it = s.upper_bound(x);
	auto jt = it;
	--it;

	ll l = *it, r = *jt;
	if (r - l > k) {
		h.insert(r);
	}
}

int main() {

	int n;
	cin >> n >> k;

	vector<pair<int, ll>> v;

	for (int i = 0; i < n; ++i) {
		int t;
		ll x;
		cin >> t >> x;
		v.push_back({t, x});
		b.push_back(x);
	}

	b.push_back(INF);
	b.push_back(-INF);

	s.insert(INF);
	s.insert(-INF);

	h.insert(INF);
	h.insert(-INF);

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	for (int i = 0; i < n; ++i) {

		int t = v[i].first;
		ll x = v[i].second;

		if (t == 1) {
			if (s.find(x) != s.end()) {
				remov(x);
			}
			else {
				add(x);
			}
		}
		else {

			auto it = h.upper_bound(x);
			auto jt = it;
			--it;

			ll l = *it, r = *jt;

			int L = lower_bound(b.begin(), b.end(), l) - b.begin();
			int R = lower_bound(b.begin(), b.end(), r) - b.begin();

			cout << query(1, 1, b.size(), L, R - 1) << endl;
		}
	}
}