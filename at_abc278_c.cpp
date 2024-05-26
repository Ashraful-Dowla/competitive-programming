/*
https://atcoder.jp/contests/abc278/tasks/abc278_c
*/
#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> mp;

int main() {

	int n, q;
	cin >> n >> q;

	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 1) {
			mp[a].insert(b);
		}
		else if (t == 2) {
			mp[a].erase(b);
		}
		else {
			if (mp[a].find(b) != mp[a].end() && mp[b].find(a) != mp[b].end()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}