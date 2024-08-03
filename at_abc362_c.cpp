/*
https://atcoder.jp/contests/abc362/tasks/abc362_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	ll l[n], r[n], sum_l = 0, sum_r = 0;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		sum_l += l[i];
		sum_r += r[i];
	}

	if (sum_l > 0 || sum_r < 0) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		ll d = min(r[i] - l[i], -sum_l);
		sum_l += d;
		l[i] += d;
	}

	cout << "Yes" << endl;
	for (int i = 0; i < n; ++i) {
		cout << l[i] << " ";
	}
	cout << endl;
}