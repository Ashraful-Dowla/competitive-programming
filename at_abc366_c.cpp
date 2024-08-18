/*
https://atcoder.jp/contests/abc366/tasks/abc366_c
*/ 
#include <bits/stdc++.h>
using namespace std;

int main() {

	int q;
	cin >> q;

	set<int> s;
	unordered_map<int, int> mp;
	while (q--) {

		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			mp[x]++;

			if (mp[x] == 1) {
				s.insert(x);
			}
		}
		else if (t == 2) {
			int x;
			cin >> x;
			mp[x]--;

			if (mp[x] == 0) {
				s.erase(x);
			}
		}
		else {
			cout << s.size() << endl;
		}
	}
}