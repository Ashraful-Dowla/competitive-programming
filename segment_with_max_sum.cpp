#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct grp
{
	ll pref, suff, sum, ans;
};

const int N = 1e5 + 10;
ll arr[N];
grp tree[4 * N];

void build(int node, int st, int nd) {
	if (st == nd) {
		grp item;
		if (arr[st] <= 0) item = {0, 0, arr[st], 0};
		else item = {arr[st], arr[st], arr[st], arr[st]};
		tree[node] = item;
		return ;
	}

	int mid = (st + nd) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, nd);

	grp left = tree[2 * node];
	grp right = tree[2 * node + 1];

	ll sum = left.sum + right.sum;
	ll pref = max(left.pref, left.sum + right.pref);
	ll suff = max(right.suff, right.sum + left.suff);
	ll ans = max(max(left.ans, right.ans), left.suff + right.pref);

	tree[node] = {pref, suff, sum, ans};
}

void update(int node, int st, int nd, int idx, int val) {
	if (st == nd) {
		arr[st] = val;
		grp item;
		if (arr[st] <= 0) item = {0, 0, arr[st], 0};
		else item = {arr[st], arr[st], arr[st], arr[st]};
		tree[node] = item;
		return ;
	}

	int mid = (st + nd) / 2;
	if (idx <= mid) update(2 * node, st, mid, idx, val);
	else update(2 * node + 1, mid + 1, nd, idx, val);

	grp left = tree[2 * node];
	grp right = tree[2 * node + 1];

	ll sum = left.sum + right.sum;
	ll pref = max(left.pref, left.sum + right.pref);
	ll suff = max(right.suff, right.sum + left.suff);
	ll ans = max(max(left.ans, right.ans), left.suff + right.pref);

	tree[node] = {pref, suff, sum, ans};
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);
	cout << tree[1].ans << endl;

	while (m--) {
		int idx, val;
		cin >> idx >> val;
		update(1, 0, n - 1, idx, val);
		cout << tree[1].ans << endl;
	}
}