/*
https://atcoder.jp/contests/abc322/tasks/abc322_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s;
	cin >> t;

	bool pf = true, sf = true;

	for (int i = 0, j = 0; i < n; ++i, ++j) {
		if (s[i] == t[j]) continue;
		pf = false;
		break;
	}

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	for (int i = 0, j = 0; i < n; ++i, ++j) {
		if (s[i] == t[j]) continue;
		sf = false;
		break;
	}

	if (pf && sf) cout << 0 << endl;
	else if (pf) cout << 1 << endl;
	else if (sf) cout << 2 << endl;
	else cout << 3 << endl;
}