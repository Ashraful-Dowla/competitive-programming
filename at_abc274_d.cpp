/*
https://atcoder.jp/contests/abc274/tasks/abc274_d
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 10005;
bool dp3[2 * M + 100], dp1[2 * M + 100], dp2[2 * M + 100];

int main() {

	int n, x, y;
	cin >> n >> x >> y;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	dp1[a[0] + M] = dp2[M] = true;

	x += M, y += M;

	for (int i = 1; i < n; ++i) {

		for (int j = 0; j <= 2 * M; ++j) {
			dp3[j] = false;
		}

		for (int j = 0; j <= 2 * M ; ++j) {
			if (i % 2 == 0) {
				dp3[j + a[i]] |= dp1[j];
				dp3[j] |= dp1[j + a[i]];
			}
			else {
				dp3[j + a[i]] |= dp2[j];
				dp3[j] |= dp2[j + a[i]];
			}
		}

		for (int j = 0; j <= 2 * M; ++j) {
			if (i % 2 == 0) {
				dp1[j] = dp3[j];
			}
			else {
				dp2[j] = dp3[j];
			}
		}
	}

	if (dp1[x] && dp2[y]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}