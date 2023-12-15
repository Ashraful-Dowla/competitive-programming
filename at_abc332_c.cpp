/*
https://atcoder.jp/contests/abc332/tasks/abc332_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	string s;

	cin >> n >> m;
	cin >> s;

	int l = 0, mx = 0, mm = m;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			l = mx;
			m = mm;
		}
		else if (s[i] == '1') {
			if (m > 0) {
				m--;
			}
			else if (l > 0) {
				l--;
			}
			else {
				mx++;
			}
		}
		else {
			if (l > 0) {
				l--;
			}
			else {
				mx++;
			}
		}
	}

	cout << mx << endl;
}