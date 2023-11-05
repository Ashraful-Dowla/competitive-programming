/*
https://atcoder.jp/contests/abc324/tasks/abc324_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	string t;

	cin >> n >> t;

	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<int> ans;
	int tz = t.size();

	for (int i = 0; i < n; ++i) {

		string s = v[i];
		int sz = s.size();

		if (sz + 1 == tz) {

			int k = 0;
			for (int j = 0; j < tz && k < sz; ++j) {
				if (t[j] == s[k]) k++;
			}

			if (k == sz) {
				ans.push_back(i + 1);
			}
		}
		else if (sz == tz) {

			int cnt = 0;
			for (int j = 0, k = 0; j < tz && k < sz; ++j, k++) {
				if (t[j] != s[k]) {
					cnt++;
				}
			}

			if (cnt <= 1) {
				ans.push_back(i + 1);
			}
		}
		else if (sz == tz + 1) {

			int j = 0;
			for (int k = 0; k < sz && j < tz; ++k) {
				if (t[j] == s[k]) j++;
			}

			if (j == tz) {
				ans.push_back(i + 1);
			}

		}
	}

	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}