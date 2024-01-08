/*
https://www.spoj.com/problems/RMQSQ/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int LOG = 17;
int m[N][LOG], a[N], bin_log[N];

//query -> O(1)
int query(int l, int r) {

	int len = r - l + 1;
	int k = bin_log[len];

	return min(m[l][k], m[r - (1 << k) + 1][k]);
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[i][0] = a[i];
	}

	bin_log[1] = 0;
	for (int i = 2; i <= n; ++i) {
		bin_log[i] = bin_log[i / 2] + 1;
	}

	// preprocess -> O(N*log(N))
	for (int j = 1; j < LOG; ++j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++i) {
			m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}