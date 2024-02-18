/*
https://atcoder.jp/contests/abc292/tasks/abc292_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	set<int> p, y, r;
	for (int i = 1; i <= n; ++i) {
		p.insert(i);
	}

	while (q--) {
		int c, x;
		cin >> c >> x;

		if (c == 1) {
			auto it = p.find(x);
			if (it != p.end()) {
				p.erase(it);
				y.insert(x);
				continue;
			}

			it = y.find(x);
			if (it != y.end()) {
				y.erase(it);
				r.insert(x);
			}
			else {
				y.insert(c);
			}
		}
		else if (c == 2) {
			auto it = p.find(x);
			if (it != p.end()) {
				p.erase(it);
				r.insert(x);
				continue;
			}

			it = y.find(x);
			if (it != y.end()) {
				y.erase(it);
				r.insert(x);
			}
		}
		else {
			if (r.find(x) == r.end()) {
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
		}
	}
}