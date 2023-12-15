/*
https://atcoder.jp/contests/abc307/tasks/abc307_b
*/
#include <bits/stdc++.h>
using namespace std;

bool chk(string s) {

	int lo = 0, hi = s.size() - 1;

	while (lo <= hi) {
		if (s[lo] != s[hi]) {
			return false;
		}
		lo++, hi--;
	}

	return true;
}

int main() {

	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (chk(v[i] + v[j]) || chk(v[j] + v[i])) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}