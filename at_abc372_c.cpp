/*
https://atcoder.jp/contests/abc372/tasks/abc372_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i + 2 < n && s[i] == 'A'
		        && s[i + 1] == 'B' && s[i + 2] == 'C') {
			ans++;
		}
	}

	while (q--) {
		int idx;
		char ch;
		cin >> idx >> ch;

		idx--;

		if (s[idx] == ch) {
			cout << ans << endl;
		}
		else {
			if (idx + 2 < n && s[idx] == 'A'
			        && s[idx + 1] == 'B' && s[idx + 2] == 'C') {
				ans--;
			}
			else if (idx >= 1 && s[idx] == 'B'
			         && s[idx - 1] == 'A' && s[idx + 1] == 'C') {
				ans--;
			}
			else if (idx >= 2 && s[idx] == 'C'
			         && s[idx - 1] == 'B' && s[idx - 2] == 'A') {
				ans--;
			}

			s[idx] = ch;

			if (idx + 2 < n && s[idx] == 'A'
			        && s[idx + 1] == 'B' && s[idx + 2] == 'C') {
				ans++;
			}
			else if (idx >= 1 && s[idx] == 'B'
			         && s[idx - 1] == 'A' && s[idx + 1] == 'C') {
				ans++;
			}
			else if (idx >= 2 && s[idx] == 'C'
			         && s[idx - 1] == 'B' && s[idx - 2] == 'A') {
				ans++;
			}

			cout << ans << endl;
		}
	}
}