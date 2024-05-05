/*
https://atcoder.jp/contests/abc351/tasks/abc351_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;
ll tree[N], tree2[N];

void add(int n, int k, int x) {
	while (k <= n) {
		tree[k] += x;
		k += (k & -k);
	}
}

void add2(int n, int k, int x) {
	while (k <= n) {
		tree2[k] += x;
		k += (k & -k);
	}
}

ll sum(int k) {

	ll res = 0;
	while (k >= 1) {
		res += tree[k];
		k -= (k & -k);
	}
	return res;
}

ll sum2(int k) {

	ll res = 0;
	while (k >= 1) {
		res += tree2[k];
		k -= (k & -k);
	}
	return res;
}

int main() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b = a;
	b.push_back(1e9);
	b.push_back(-1e9);

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	ll ans = 0;
	for (int x : a) {
		int idx = lower_bound(b.begin(), b.end(), x) - b.begin();

		ans += sum(idx) * x - sum2(idx);

		add(n, idx, 1);
		add2(n, idx, x);
	}

	cout << ans << endl;

}