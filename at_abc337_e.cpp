/*
https://atcoder.jp/contests/abc337/tasks/abc337_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	int n, res = 0;
	cin >> n;

	int m = ceil(log2(n));

	cout << m << endl;

	vector<int> bits[m];
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((j & (1 << i))) {
				bits[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << bits[i].size() << " ";
		for (int x : bits[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	cout << flush;

	cin >> s;
	for (int i = 0; i < m; ++i) {
		if (s[i] == '1') {
			res |= 1 << i;
		}
	}

	if (res == 0) cout << n << endl;
	else cout << res << endl;

	return 0;
}