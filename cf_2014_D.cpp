//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2014/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, d, k;
	cin >> n >> d >> k;

	vector<int> v(n + 5, 0);

	for (int i = 0; i < k; ++i) {
		int l, r;
		cin >> l >> r;
		v[max(1, l - d + 1)]++, v[r + 1]--;
	}

	for (int i = 1; i <= n; ++i) {
		v[i] += v[i - 1];
	}

	int mx = -1, b = 1;
	for (int i = 1; i <= n - d + 1; ++i) {
		if (v[i] > mx) {
			mx = v[i];
			b = i;
		}
	}

	int mn = 1e9, m = 1;
	for (int i = 1; i <= n - d + 1; ++i) {
		if (v[i] < mn) {
			mn = v[i];
			m = i;
		}
	}

	cout << b << " " << m << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}