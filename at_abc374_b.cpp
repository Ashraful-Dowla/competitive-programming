/*
https://atcoder.jp/contests/abc374/tasks/abc374_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	string t;
	cin >> t;

	int n = s.size(), m = t.size();

	if (n < m) {
		for (int i = 0; i < m - n; ++i) {
			s.push_back('#');
		}
	}
	else if (n > m) {
		for (int i = 0; i < n - m; ++i) {
			t.push_back('#');
		}
	}

	int i = 0, ans = 0;
	while (i < max(n, m)) {
		if (s[i] != t[i]) {
			ans = i + 1;
			break;
		}
		i++;
	}

	cout << ans << endl;
}