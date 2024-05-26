/*
https://atcoder.jp/contests/abc355/tasks/abc355_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> c;

	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		c.push_back(x);
		s.insert(x);
	}

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		c.push_back(x);
	}

	sort(c.begin(), c.end());

	for (int i = 0; i + 1 < n + m; ++i) {
		if (s.find(c[i]) != s.end() && s.find(c[i + 1]) != s.end()) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
}