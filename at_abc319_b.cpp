/*
https://atcoder.jp/contests/abc319/tasks/abc319_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string ans;

	for (int i = 0; i <= n; ++i) {
		int val = INT_MAX;
		for (int j = 1; j <= 9; ++j) {
			if (n % j == 0 && i % (n / j) == 0) {
				val = min(val, j);
			}
		}

		if (val != INT_MAX) {
			ans.push_back((val + '0'));
		}
		else {
			ans.push_back('-');
		}
	}

	cout << ans << endl;
}