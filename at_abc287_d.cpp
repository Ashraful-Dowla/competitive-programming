/*
https://atcoder.jp/contests/abc287/tasks/abc287_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s, t;
	cin >> s;
	cin >> t;

	int tz = t.size();
	int sz = s.size();

	vector<bool> first(tz + 2, true), last(sz + 2, true);

	for (int i = 0; i < t.size(); ++i) {
		if (s[i] == t[i] || s[i] == '?' || t[i] == '?') {
			if (i == 0) continue;
			first[i] = first[i - 1];
		}
		else {
			first[i] = false;
		}
	}

	for (int i = sz - 1, j = tz - 1; j >= 0; --i, --j) {
		if (s[i] == t[j] || s[i] == '?' || t[j] == '?') {
			last[i] = last[i + 1];
		}
		else {
			last[i] = false;
		}
	}

	for (int x = 0; x <= tz; ++x) {
		if (x == 0) {
			cout << (last[sz - tz] ? "Yes" : "No") << endl;
		}
		else {
			if (first[x - 1] && last[sz - tz + x]) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}