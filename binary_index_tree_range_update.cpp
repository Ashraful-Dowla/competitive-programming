#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int tree[N], arr[N], n, u;

void add(int k, int x) {
	while (k <= n) {
		tree[k] += x;
		k += (k & -k);
	}
}

int query(int k) {
	int sum = 0;
	while (k >= 1) {
		sum += tree[k];
		k -= (k & -k);
	}
	return sum;
}

int main() {
	cin >> n >> u;
	while (u--) {
		int l, r, inc;
		cin >> l >> r >> inc;
		add(l, inc);
		add(r + 1, -inc);
	}
	int q;
	cin >> q;
	while (q--) {
		int w;
		cin >> w;
		cout << query(w) << endl;
	}

}