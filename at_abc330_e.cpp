/*
https://atcoder.jp/contests/abc330/tasks/abc330_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int>v(n);
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];

		mp[v[i]]++;
	}

	set<int> s;
	for (int i = 0; i <= n; ++i) {
		if (mp[i] == 0) {
			s.insert(i);
		}
	}

	while (q--) {
		int i, x;
		cin >> i >> x;

		--i;

		if (mp[v[i]] == 1) {
			s.insert(v[i]);
			mp[v[i]]--;
		}
		else {
			mp[v[i]]--;
		}

		v[i] = x;

		if (mp[v[i]] == 0) {
			s.erase(v[i]);
			mp[v[i]]++;
		}
		else {
			mp[v[i]]++;
		}

		cout << *s.begin() << endl;
	}
}