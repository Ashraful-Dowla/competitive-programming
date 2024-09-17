/*
https://atcoder.jp/contests/abc370/tasks/abc370_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s, t;
	cin >> s;
	cin >> t;

	int n = s.size();

	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			m++;
		}
	}

	vector<string> ans;
	while (m--) {

		vector<string> temp;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				char ch = s[i];
				s[i] = t[i];
				temp.push_back(s);
				s[i] = ch;
			}
		}

		sort(temp.begin(), temp.end());
		ans.push_back(temp[0]);
		s = temp[0];
	}

	cout << ans.size() << endl;
	for (string p : ans) {
		cout << p << endl;
	}
}