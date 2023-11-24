/*
https://atcoder.jp/contests/abc314/tasks/abc314_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int q;
	cin >> q;

	int ok = -1;
	set<int> lo, up;

	while (q--) {
		int t, x;
		char c;

		cin >> t >> x >> c;
		--x;
		if (t == 1) {
			s[x] = c;

			if (islower(c)) {
				lo.insert(x);
			}
			else {
				up.insert(x);
			}
		}
		else if (t == 2) {
			ok = 0;
			up.clear();
		}
		else {
			ok = 1;
			lo.clear();
		}
	}

	if (ok == -1) {
		cout << s << endl;
	}
	else if (ok == 0) {
		for (int i = 0; i < n; ++i) {
			if (up.find(i) != up.end()) {
				cout << s[i];
			}
			else {
				char ch = tolower(s[i]);
				cout << ch;
			}
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (lo.find(i) != lo.end()) {
				cout << s[i];
			}
			else {
				char ch = toupper(s[i]);
				cout << ch;
			}
		}
		cout << endl;
	}
}