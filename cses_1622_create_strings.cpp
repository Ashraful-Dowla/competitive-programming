/*
https://cses.fi/problemset/task/1622
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	vector<int> v;
	map<string, bool> mp;
	vector<string> ans;

	for (int i = 0; i < s.size(); ++i) {
		v.push_back(i);
	}

	do {
		string t;
		for (int x : v) {
			t.push_back(s[x]);
		}

		if (!mp[t]) {
			ans.push_back(t);
			mp[t] = true;
		}

	} while (next_permutation(v.begin(), v.end()));

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (string s : ans) {
		cout << s << endl;
	}
}