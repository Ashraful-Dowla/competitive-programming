/*
https://atcoder.jp/contests/abc356/tasks/abc356_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<long long> a(m);

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	vector<long long> x(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			long long p;
			cin >> p;
			x[j] += p;
		}
	}

	for (int i = 0; i < m; ++i) {
		if (a[i] <= x[i]) {
			continue;
		}

		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}