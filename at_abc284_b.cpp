/*
https://atcoder.jp/contests/abc284/tasks/abc284_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			if (x & 1) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}