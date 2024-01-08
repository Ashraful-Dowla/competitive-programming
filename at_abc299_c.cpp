/*
https://atcoder.jp/contests/abc299/tasks/abc299_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	s = "-" + s + "-";

	vector<int> v;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-') {
			v.push_back(i);
		}
	}

	if (v.size() > 2) {
		int mx = 0;
		for (int i = 1; i < v.size(); ++i) {
			mx = max(mx, v[i] - v[i - 1]);
		}

		cout << (mx == 1 ? -1 : mx - 1)  << endl;
	}
	else {
		cout << -1 << endl;
	}
}