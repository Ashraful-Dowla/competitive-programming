/*
https://atcoder.jp/contests/abc360/tasks/abc360_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s, t;
	cin >> s >> t;

	for (int i = 1; i < s.size(); ++i) {
		vector<string> v;
		for (int j = 0; j < s.size(); j += i) {
			string p = s.substr(j, i);
			v.push_back(p);
		}

		vector<string> ans(i);

		for (int k = 0; k < i; ++k) {
			for (int j = 0; j < v.size(); ++j) {
				if (k < v[j].size()) {
					ans[k].push_back(v[j][k]);
				}
			}
		}

		for (string p : ans) {
			if (p == t) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}