/*
https://atcoder.jp/contests/abc295/tasks/abc295_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> s(n);

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	map<string, bool> mp;

	mp["and"] = mp["not"] = mp["that"] = mp["the"] = mp["you"] = true;

	for (string res : s) {
		if (mp[res]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
}