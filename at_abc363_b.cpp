/*
https://atcoder.jp/contests/abc363/tasks/abc363_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, t, p;
	cin >> n >> t >> p;

	int l[n];
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}

	for (int i = 0; i <= 100; ++i) {
		int ct = 0;
		for (int j = 0; j < n; ++j) {
			if (l[j] + i >= t) {
				ct++;
			}
		}
		if (ct >= p) {
			cout << i << endl;
			return 0;
		}
	}
}