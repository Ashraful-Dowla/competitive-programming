/*
https://atcoder.jp/contests/abc331/tasks/abc331_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
typedef long long ll;

ll tree[4 * N], a[N], b[N], bb[N];
vector<int> graph[N];

void build(int node, int st, int nd) {

	if (st == nd) {
		tree[node] = b[st];
		return ;
	}

	int mid = (st + nd) / 2;

	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int st, int nd, int idx, int val) {

	if (st == nd) {
		tree[node] = b[st] = val;
		return ;
	}
	int mid = (st + nd) / 2;

	if (idx <= mid) {
		update(2 * node, st, mid, idx, val);
	}
	else {
		update(2 * node + 1, mid + 1, nd, idx, val);
	}

	tree[node] = max(tree[2 * node], tree[2 * node + 1]);

}

int main() {

	int n, m, l;
	cin >> n >> m >> l;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		bb[i] = b[i];
	}

	for (int i = 0; i < l; ++i) {
		int c, d;
		cin >> c >> d;
		graph[c].push_back(d);
	}

	build(1, 1, m);

	vector<ll> mx(n + 1);

	for (int i = 1; i <= n; ++i) {

		for (int d : graph[i]) {
			update(1, 1, m, d, 0);
		}

		mx[i] = tree[1];

		for (int d : graph[i]) {
			update(1, 1, m, d, bb[d]);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, a[i] + mx[i]);
	}

	cout << ans << endl;
}