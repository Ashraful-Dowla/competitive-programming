/*
https://atcoder.jp/contests/abc294/tasks/abc294_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	set<int> s;
	for (int i = 1; i <= n; ++i) {
		s.insert(i);
	}

	set<int> a;

	while (q--) {
		int t;
		cin >> t;

		if (t == 2) {
			int x;
			cin >> x;
			a.erase(x);
		}
		else if (t == 3) {
			cout << *a.begin() << endl;
		}
		else {
			int x = *s.begin();
			s.erase(x);
			a.insert(x);
		}
	}
}