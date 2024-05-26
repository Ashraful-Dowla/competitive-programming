#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int tree[4 * N];

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

int main() {

	// vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
	vector<int> nums = { 10, 8, 3, 1, 6, 4, 2, 9};

	vector<int> v = nums;

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int n = nums.size();
	vector<int> lis(n);

	for (int i = 0; i < n; ++i) {

		int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();

		lis[i] = 1 + query(1, 0, v.size() - 1, 0, idx - 1);

		update(1, 0, v.size() - 1, idx, lis[i]);

	}

	for (int x : lis) {
		cout << x << " ";
	}
	cout << endl;
}